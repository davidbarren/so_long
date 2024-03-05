/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_counters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:51:53 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/19 17:51:53 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_element(char **arr, char element)
{
	int	i;
	int	result;
	int	k;

	result = 0;
	i = 0;
	k = 0;
	while (arr[i])
	{
		while (arr[i][k])
		{
			if (arr[i][k] == element)
				result++;
			k++;
		}
		k = 0;
		i++;
	}
	return (result);
}

void	update_elements(t_map *map_struct)
{
	map_struct->collect_count = find_element(map_struct->map, 'C');
	map_struct->player_count = find_element(map_struct->map, 'P');
	map_struct->exit_count = find_element(map_struct->map, 'E');
}

int	parse_map(char **arr)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (arr[i])
	{
		if (is_valid_element(arr[i]))
			i++;
		else
		{
			ft_printerror(INVALID_ELEMENT);
			return (0);
		}
	}
	return (1);
}

int	is_valid_element(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C' || str[i] == 'P' || str[i] == 'E')
			i++;
		else if (str[i] == '1' || str[i] == '0')
			i++;
		else
			return (0);
	}
	return (1);
}

void	update_start(t_map *map_struct, char **arr)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (arr[i])
	{
		while (arr[i][k])
		{
			if (arr[i][k] == 'P')
			{
				map_struct->x_start = k;
				map_struct->y_start = i;
				return ;
			}
			k++;
		}
		k = 0;
		i++;
	}
}
