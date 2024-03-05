/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:36:12 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/29 17:36:13 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hooks_function(mlx_key_data_t data, void *param)
{
	t_map	*map;

	map = param;
	if ((data.key == MLX_KEY_W || data.key == MLX_KEY_UP) && data.action == 1)
		move_up(map);
	else if ((data.key == MLX_KEY_S || data.key == MLX_KEY_DOWN)
		&& data.action == 1)
		move_down(map);
	else if ((data.key == MLX_KEY_A || data.key == MLX_KEY_LEFT)
		&& data.action == 1)
		move_left(map);
	else if ((data.key == MLX_KEY_D || data.key == MLX_KEY_RIGHT)
		&& data.action == 1)
		move_right(map);
	else if (data.key == MLX_KEY_ESCAPE && data.action == 1)
		mlx_close_window(map->mlx);
}

void	move_left(t_map *map)
{
	if (map->map[map->y_pos][map->x_pos - 1] != '1')
	{
		map->imgs->player->instances->x -= map->sq_sz;
		map->imgs->player_m->instances->x -= map->sq_sz;
		map->imgs->player_m->instances->enabled = 1;
		map->imgs->player->instances->enabled = 0;
		map->x_pos -= 1;
		map->move_count += 1;
		ft_printf("Move count: %u\n", map->move_count);
	}
	if (map->map[map->y_pos][map->x_pos] == 'C')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		hide_collectible(map);
		map->collect_count -= 1;
	}
	if (map->map[map->y_pos][map->x_pos] == 'E' && !map->collect_count)
	{
		ft_printf(WINNING_MSG);
		mlx_close_window(map->mlx);
	}
}

void	move_up(t_map *map)
{
	if (map->map[map->y_pos - 1][map->x_pos] != '1')
	{
		map->imgs->player->instances->y -= map->sq_sz;
		map->imgs->player_m->instances->y -= map->sq_sz;
		map->y_pos -= 1;
		map->move_count += 1;
		ft_printf("Move count: %u\n", map->move_count);
	}
	if (map->map[map->y_pos][map->x_pos] == 'C')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		hide_collectible(map);
		map->collect_count -= 1;
	}
	if (map->map[map->y_pos][map->x_pos] == 'E' && !map->collect_count)
	{
		ft_printf(WINNING_MSG);
		mlx_close_window(map->mlx);
	}
}

void	move_right(t_map *map)
{
	if (map->map[map->y_pos][map->x_pos + 1] != '1')
	{
		map->imgs->player->instances->x += map->sq_sz;
		map->imgs->player_m->instances->x += map->sq_sz;
		map->imgs->player_m->instances->enabled = 0;
		map->imgs->player->instances->enabled = 1;
		map->x_pos += 1;
		map->move_count += 1;
		ft_printf("Move count: %u\n", map->move_count);
	}
	if (map->map[map->y_pos][map->x_pos] == 'C')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		hide_collectible(map);
		map->collect_count -= 1;
	}
	if (map->map[map->y_pos][map->x_pos] == 'E' && !map->collect_count)
	{
		ft_printf(WINNING_MSG);
		mlx_close_window(map->mlx);
	}
}

void	move_down(t_map *map)
{
	if (map->map[map->y_pos + 1][map->x_pos] != '1')
	{
		map->imgs->player->instances->y += map->sq_sz;
		map->imgs->player_m->instances->y += map->sq_sz;
		map->y_pos += 1;
		map->move_count += 1;
		ft_printf("Move count: %u\n", map->move_count);
	}
	if (map->map[map->y_pos][map->x_pos] == 'C')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		hide_collectible(map);
		map->collect_count -= 1;
	}
	if (map->map[map->y_pos][map->x_pos] == 'E' && !map->collect_count)
	{
		ft_printf(WINNING_MSG);
		mlx_close_window(map->mlx);
	}
}
