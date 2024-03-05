/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:43:23 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/14 15:44:07 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
		free(arguments[i++]);
	free(arguments);
}

void	ft_free_mlx(t_map *map, int errcode)
{
	delete_txtrs(map);
	remove_images(map);
	free_split(map->map);
	free(map->imgs->collec);
	if (errcode == -1)
	{
		ft_printerror("Error\nMLX42 Function Failure");
		exit (errcode);
	}
	if (errcode == -2)
	{
		ft_printerror("Error\nFailed to Allocate Memory for Collectibles");
		exit (errcode);
	}
}

int	main(int argc, char **argv)
{
	t_map	map_struct;
	t_img	images;
	t_txt	txtrs;

	if (check_map_args(argc, argv))
		return (1);
	ft_memset(&map_struct, 0, sizeof(map_struct));
	map_struct.imgs = &images;
	map_struct.txtrs = &txtrs;
	open_map(&map_struct, obtain_fd(argv[1]));
	update_elements(&map_struct);
	if (!check_validity(&map_struct))
		return (1);
	update_start(&map_struct, map_struct.map);
	if (!path_validity(&map_struct))
		return (1);
	init_game(&map_struct);
	mlx_loop(map_struct.mlx);
	ft_free_mlx(&map_struct, 0);
	mlx_terminate(map_struct.mlx);
	return (0);
}
