/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:15:08 by dbarrene          #+#    #+#             */
/*   Updated: 2024/03/04 18:15:09 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_floor(t_map *map)
{
	if ((mlx_image_to_window(map->mlx, map->imgs->floor, 0, 0)) < 0)
		ft_free_mlx(map, -1);
}

void	place_wall(t_map *map)
{
	if (mlx_image_to_window(map->mlx, map->imgs->wall, \
	map->x_pos * map->sq_sz, map->y_pos * map->sq_sz) < 0)
		ft_free_mlx(map, -1);
}

void	place_player_models(t_map *map)
{
	if (mlx_image_to_window(map->mlx, map->imgs->player, \
	map->x_pos * map->sq_sz, map->y_pos * map->sq_sz) < 0)
		ft_free_mlx(map, -1);
	if (mlx_image_to_window(map->mlx, map->imgs->player_m, \
	map->x_pos * map->sq_sz, map->y_pos * map->sq_sz) < 0)
		ft_free_mlx(map, -1);
	map->imgs->player_m->instances->enabled = 0;
}

void	place_exit(t_map *map)
{
	if (mlx_image_to_window(map->mlx, map->imgs->exit, \
	map->x_pos * map->sq_sz, map->y_pos * map->sq_sz) < 0)
		ft_free_mlx(map, -1);
}
