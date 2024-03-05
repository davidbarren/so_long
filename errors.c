/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:43 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/14 15:44:45 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printerror(MISSING_MAP));
	else if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (ft_printerror(INVALID_FORMAT));
	return (0);
}

int	ft_map_is_closed(t_map *map_struct)
{
	size_t	i;

	i = 0;
	while (i < map_struct->height && map_struct->map[i])
	{
		if ((map_struct->map[i][0] != '1')
		|| (map_struct->map[i][(map_struct->width - 1)] != '1'))
		{
			ft_printerror(INVALID_MAP);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map_struct->width && map_struct->map[i])
	{
		if ((map_struct->map[0][i] != '1')
		|| (map_struct->map[(map_struct->height - 1)][i] != '1'))
		{
			ft_printerror(INVALID_MAP);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_shape(t_map *map_struct)
{
	int	i;

	i = 0;
	while (map_struct->map[i])
	{
		if (ft_strlen(map_struct->map[i]) != map_struct->width)
		{
			ft_printerror(INVALID_SHAPE);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_elements(t_map *map_struct)
{
	if (map_struct->exit_count != 1)
	{
		ft_printerror(DUPLICATE_EXIT);
		return (0);
	}
	if (map_struct->player_count != 1)
	{
		ft_printerror(DUPLICATE_PLAYERS);
		return (0);
	}
	if (map_struct->collect_count < 1)
	{
		ft_printerror(NO_COLLECTIBLES);
		return (0);
	}
	return (1);
}

int	is_valid_path(t_temp temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp.map[i])
	{
		while (temp.map[i][j])
		{
			if (temp.map[i][j] == 'C' || temp.map[i][j] == 'E')
			{
				ft_printerror(INVALID_PATH);
				free_split(temp.map);
				return (0);
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	free_split(temp.map);
	return (1);
}
