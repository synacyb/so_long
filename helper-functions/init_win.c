/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:52:40 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/06 11:11:58 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*init_win(t_textur *data, int length, int width)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	data->win = mlx_new_window(data->mlx, length * 35, width * 35, "so_long");
	if (!data->mlx)
		return (NULL);
}
