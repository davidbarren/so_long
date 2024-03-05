/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:51:57 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/20 12:51:58 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, size_t height)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = malloc((height + 1) * sizeof (char *));
	if (!map_dup)
		return (NULL);
	while (map[i])
	{
		map_dup[i] = ft_strdup(map[i]);
		i++;
	}
	map_dup[i] = 0;
	return (map_dup);
}

t_temp	make_temp_struct(t_map *map_struct)
{
	t_temp	temp;
	int		i;

	i = 0;
	ft_memset(&temp, 0, sizeof(temp));
	temp.current_x = map_struct->x_start;
	temp.current_y = map_struct->y_start;
	temp.height = map_struct->height;
	temp.width = map_struct->width;
	temp.map = copy_map(map_struct->map, map_struct->height);
	return (temp);
}

void	fill(t_temp temp, int current_x, int current_y)
{
	if (current_x >= (int)temp.width || current_y >= (int)temp.height
		|| current_x <= 0 || current_y <= 0
		|| temp.map[current_y][current_x] == '1')
		return ;
	if ((temp.map[current_y][current_x] == 'C')
		|| (temp.map[current_y][current_x] == '0')
		|| (temp.map[current_y][current_x] == 'E')
		|| (temp.map[current_y][current_x] == 'P'))
	{
		temp.map[current_y][current_x] = 'X';
		fill(temp, current_x + 1, current_y);
		fill(temp, current_x - 1, current_y);
		fill(temp, current_x, current_y - 1);
		fill(temp, current_x, current_y + 1);
	}
}

int	path_validity(t_map *map_struct)
{
	t_temp	temp;
	int		i;

	i = 0;
	temp = make_temp_struct(map_struct);
	fill(temp, temp.current_x, temp.current_y);
	if (!is_valid_path(temp))
	{
		free_split(map_struct->map);
		return (0);
	}
	return (1);
}

void	ft_error_exit(int errcode)
{
	ft_printerror("Error\nEmpty map");
	exit (errcode);
}
