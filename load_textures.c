/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:15:25 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/26 15:15:26 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_map *map)
{
	map->txtrs->wall = mlx_load_png(WALL_PATH);
	if (!map->txtrs->wall)
		ft_free_mlx(map, -1);
	map->txtrs->floor = mlx_load_png(FLOOR_PATH);
	if (!map->txtrs->floor)
		ft_free_mlx(map, -1);
	map->txtrs->player = mlx_load_png(CHAR_PATH);
	if (!map->txtrs->player)
		ft_free_mlx(map, -1);
	map->txtrs->player_m = mlx_load_png(CHAR_M_PATH);
	if (!map->txtrs->player_m)
		ft_free_mlx(map, -1);
	map->txtrs->collec = mlx_load_png(COLLEC_PATH);
	if (!map->txtrs->collec)
		ft_free_mlx(map, -1);
	map->txtrs->exit = mlx_load_png(EXIT_PATH);
	if (!map->txtrs->exit)
		ft_free_mlx(map, -1);
}

void	load_images(t_map *map)
{
	size_t	i;

	i = 0;
	map->imgs->wall = mlx_texture_to_image(map->mlx, map->txtrs->wall);
	map->imgs->floor = mlx_texture_to_image(map->mlx, map->txtrs->floor);
	map->imgs->exit = mlx_texture_to_image(map->mlx, map->txtrs->exit);
	if (!map->imgs->wall || !map->imgs->floor || !map->imgs->exit)
		ft_free_mlx(map, -1);
	map->imgs->player = mlx_texture_to_image(map->mlx, map->txtrs->player);
	map->imgs->player_m = mlx_texture_to_image(map->mlx, map->txtrs->player_m);
	if (!map->imgs->player || !map->imgs->player_m)
		ft_free_mlx(map, -1);
	while (i < map->collect_count)
	{
		map->imgs->collec[i] = mlx_texture_to_image \
		(map->mlx, map->txtrs->collec);
		if (!map->imgs->collec[i++])
			ft_free_mlx(map, -1);
	}
	resize_images(map);
	place_components(map);
}

void	remove_images(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->imgs->wall)
		mlx_delete_image(map->mlx, map->imgs->wall);
	if (map->imgs->floor)
		mlx_delete_image(map->mlx, map->imgs->floor);
	if (map->imgs->player)
		mlx_delete_image(map->mlx, map->imgs->player);
	if (map->imgs->player_m)
		mlx_delete_image(map->mlx, map->imgs->player_m);
	while (map->imgs->collec[i])
		mlx_delete_image(map->mlx, map->imgs->collec[i++]);
	if (map->imgs->exit)
		mlx_delete_image(map->mlx, map->imgs->exit);
}

void	delete_txtrs(t_map *map)
{
	if (map->txtrs->wall)
		mlx_delete_texture(map->txtrs->wall);
	if (map->txtrs->floor)
		mlx_delete_texture(map->txtrs->floor);
	if (map->txtrs->player)
		mlx_delete_texture(map->txtrs->player);
	if (map->txtrs->player_m)
		mlx_delete_texture(map->txtrs->player_m);
	if (map->txtrs->collec)
		mlx_delete_texture(map->txtrs->collec);
	if (map->txtrs->exit)
		mlx_delete_texture(map->txtrs->exit);
}

void	resize_images(t_map *map)
{
	size_t	i;

	i = 0;
	if (!mlx_resize_image(map->imgs->wall, map->sq_sz, map->sq_sz))
		ft_free_mlx(map, -1);
	if (!mlx_resize_image(map->imgs->floor, \
		map->sq_sz * map->width, map->sq_sz * map->height))
		ft_free_mlx(map, -1);
	if (!mlx_resize_image(map->imgs->player, map->sq_sz, map->sq_sz))
		ft_free_mlx(map, -1);
	if (!mlx_resize_image(map->imgs->player_m, map->sq_sz, map->sq_sz))
		ft_free_mlx(map, -1);
	while (i < map->collect_count)
	{
		if (!mlx_resize_image(map->imgs->collec[i++], map->sq_sz, map->sq_sz))
			ft_free_mlx(map, -1);
	}
	if (!mlx_resize_image(map->imgs->exit, map->sq_sz, map->sq_sz))
		ft_free_mlx(map, -1);
}
