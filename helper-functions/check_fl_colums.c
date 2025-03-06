/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fl_colums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:48:34 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/06 11:07:51 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_fl_colums(t_map *data)
{
	t_sdata	s_data;

	s_data.i = 0;
	s_data.j = 0;
	while (s_data.i < data->rows)
	{
		if (data->copy_map[s_data.i][0] != '1')
			return (0);
		s_data.i++;
	}
	s_data.i = 0;
	while (s_data.i < data->rows)
	{
		if (data->copy_map[s_data.i][data->columns - 1] != '1')
			return (0);
		s_data.i++;
	}
	return (1);
}
