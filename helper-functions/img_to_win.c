/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:14:09 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/08 06:27:21 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img_to_window(t_map *data, t_sdata *var)
{
	if (data->map[var->i][var->j] == '1')
		mlx_put_image_to_window(data->data->mlx, data->data->win,
			data->data->wall_img, var->j * 80, var->i * 80);
	if (data->map[var->i][var->j] == '0')
		mlx_put_image_to_window(data->data->mlx, data->data->win,
			data->data->floor_img, var->j * 80, var->i * 80);
	if (data->map[var->i][var->j] == 'P')
		mlx_put_image_to_window(data->data->mlx, data->data->win,
			data->data->player_img, var->j * 80, var->i * 80);
	if (data->map[var->i][var->j] == 'E')
		mlx_put_image_to_window(data->data->mlx, data->data->win,
			data->data->exit_img, var->j * 80, var->i * 80);
	if (data->map[var->i][var->j] == 'C')
		mlx_put_image_to_window(data->data->mlx, data->data->win,
			data->data->coin_img, var->j * 80, var->i * 80);
}
