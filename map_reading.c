/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:36:30 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/22 13:36:31 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(t_map *map_struct, int fd)
{
	int		i;
	char	*fullmap;
	char	*temp;

	fullmap = NULL;
	i = 0;
	temp = get_next_line(fd);
	if (!temp)
		ft_error_exit(-1);
	while (temp)
	{
		if (!parse_line(temp, fullmap))
			exit (-1);
		fullmap = ft_strjoin_mod(fullmap, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	map_struct->map = ft_split(fullmap, '\n');
	free (fullmap);
	map_struct->width = ft_strlen(map_struct->map[0]);
	map_struct->height = ft_get_height(map_struct->map);
	return ;
}

int	obtain_fd(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printerror(FAKE_MAP);
		exit (-1);
	}
	return (fd);
}

int	ft_get_height(char **arr)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (arr[i])
	{
		if (*arr[i] != '\n')
		{
			i++;
			height++;
		}
		else
			return (0);
	}
	return (height);
}

int	check_validity(t_map *map_struct)
{
	if (!ft_map_is_closed(map_struct) || !ft_check_shape(map_struct))
	{
		free_split(map_struct->map);
		return (0);
	}
	if (!ft_check_elements(map_struct) ||!parse_map(map_struct->map))
	{
		free_split(map_struct->map);
		return (0);
	}
	if (map_struct->height > 130 || map_struct->width > 130)
	{
		free_split(map_struct->map);
		ft_printerror("Error\nMap is too large and exceeds window size");
		return (0);
	}
	return (1);
}

int	parse_line(char *line, char *total)
{
	if (*line == '\n')
	{
		free(line);
		free(total);
		ft_printerror(INVALID_MAP);
		line = NULL;
		return (0);
	}
	return (1);
}
