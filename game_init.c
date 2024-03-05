/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:12:31 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/29 17:12:31 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_components(t_map	*map)
{
	place_floor(map);
	while (map->map[map->y_pos])
	{
		while (map->map[map->y_pos][map->x_pos])
		{
			if (map->map[map->y_pos][map->x_pos] == '1')
				place_wall(map);
			else if (map->map[map->y_pos][map->x_pos] == 'P')
				place_player_models(map);
			else if (map->map[map->y_pos][map->x_pos] == 'E')
				place_exit(map);
			map->x_pos++;
		}
		map->x_pos = 0;
		map->y_pos++;
	}
}

void	init_game(t_map *map)
{
	map->xs = WIDTH / map->width;
	map->ys = HEIGHT / map->height;
	if (map->xs > map->ys)
		map->sq_sz = map->ys;
	else
		map->sq_sz = map->xs;
	map->mlx = mlx_init((int)(map->sq_sz * map->width), \
	(int)(map->sq_sz * map->height), "Bored Ape Crypto Scam", 0);
	if (!map->mlx)
		ft_free_mlx(map, -1);
	map->imgs->collec = ft_calloc(map->collect_count, sizeof (mlx_image_t *));
	if (!map->imgs->collec)
		ft_free_mlx(map, -2);
	load_textures(map);
	load_images(map);
	load_collectibles(map);
	update_positions(map);
	mlx_key_hook(map->mlx, &hooks_function, map);
}

void	update_positions(t_map *map)
{
	map->y_pos = map->y_start;
	map->x_pos = map->x_start;
}

void	load_collectibles(t_map *map)
{
	int	i;

	map->x_pos = 0;
	map->y_pos = 0;
	i = 0;
	while (map->map[map->y_pos])
	{
		while (map->map[map->y_pos][map->x_pos])
		{
			if (map->map[map->y_pos][map->x_pos] == 'C')
			{
				if (mlx_image_to_window(map->mlx, map->imgs->collec[i++], \
					map->x_pos * map->sq_sz, map->y_pos * map->sq_sz) < 0)
					ft_free_mlx(map, -1);
			}
			map->x_pos++;
		}
		map->x_pos = 0;
		map->y_pos++;
	}
}

void	hide_collectible(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->imgs->collec[i])
	{
		if (map->x_pos * (int)map->sq_sz == map->imgs->collec[i]->instances->x
			&& map->y_pos * (int)map->sq_sz == \
			map->imgs->collec[i]->instances->y)
		{
			map->imgs->collec[i]->instances->enabled = 0;
			break ;
		}
		i++;
	}
}
