/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:32:57 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/06 11:09:39 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	floodfill(char **tab, int x, int y, t_map *data)
{
	if (y < 0 || x < 0 || y >= data->rows || x >= data->columns
		|| tab[y][x] == '1' || tab[y][x] == 'F' || tab[y][x] == 'E')
		return ;
	tab[y][x] = 'F';
	floodfill(tab, x + 1, y, data);
	floodfill(tab, x - 1, y, data);
	floodfill(tab, x, y + 1, data);
	floodfill(tab, x, y - 1, data);
}

void	floodfill2(char **tab, int x, int y, t_map *data)
{
	if (y < 0 || x < 0 || y >= data->rows || x >= data->columns
		|| tab[y][x] == '1' || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	floodfill2(tab, x + 1, y, data);
	floodfill2(tab, x - 1, y, data);
	floodfill2(tab, x, y + 1, data);
	floodfill2(tab, x, y - 1, data);
}
