/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:26:49 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/06 10:21:31 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(t_map *data)
{
	t_sdata	s_data;

	s_data.i = 1;
	while (data->copy_map[s_data.i])
	{
		s_data.j = 0;
		s_data.j = effective_length(data->copy_map[s_data.i]);
		if (data->columns != s_data.j)
			return (0);
		s_data.i++;
	}
	return (1);
}

int	is_closed_by_walls(t_map *data)
{
	t_sdata	s_data;

	s_data.i = 0;
	s_data.j = 0;
	while (data->copy_map[0][s_data.j] && s_data.j < data->columns)
	{
		if (data->copy_map[0][s_data.j] != '1')
			return (0);
		s_data.j++;
	}
	s_data.j = 0;
	while (data->copy_map[data->rows - 1][s_data.j] && s_data.j < data->columns)
	{
		if (data->copy_map[data->rows - 1][s_data.j] != '1')
			return (0);
		s_data.j++;
	}
	if (!check_fl_colums(data))
		return (0);
	return (1);
}

int	check_valid_character(t_map *data)
{
	t_sdata	s_data;
	char	c;

	s_data.i = 0;
	s_data.j = 0;
	while (data->copy_map[s_data.i])
	{
		s_data.j = 0;
		while (data->copy_map[s_data.i][s_data.j] && s_data.j < data->columns)
		{
			c = data->copy_map[s_data.i][s_data.j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (0);
			s_data.j++;
		}
		s_data.i++;
	}
	if (!validate_map_elements(data))
		return (0);
	return (1);
}

int	check_all_cases(t_map *data)
{
	t_sdata	info;

	if (!is_rectangular(data))
		return (custom_error("this map is not rectangular\n"), 0);
	if (!is_closed_by_walls(data))
		return (custom_error("Error this walls!"), 0);
	if (!check_valid_character(data))
		return (custom_error("invalid character in the map"), 0);
	get_pos_of_player(data, &info);
	floodfill(data->copy_map, info.pos_x, info.pos_y, data);
	if (!validate_reachability(data->copy_map, data->rows, data->columns))
		return (custom_error("this map is not reachabile!"), 0);
	free_matrix(data->copy_map);
	data->copy_map = ft_strcpymap(data->map, data->rows, data->columns);
	floodfill2(data->copy_map, info.pos_x, info.pos_y, data);
	if (!validate_reachability2(data->copy_map, data->rows, data->columns))
		return (custom_error("this map is not reachabile!"), 0);
	return (1);
}
