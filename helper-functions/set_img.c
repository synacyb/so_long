/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:29:21 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/08 07:38:10 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_errors(t_textur *data)
{
	if (!data->wall_img)
		return (custom_error("failed to allocate wall_img"), 0);
	if (!data->floor_img)
		return (custom_error("failed to allocate floor_img"), 0);
	if (!data->player_img)
		return (custom_error("failed to allocate player_img"), 0);
	if (!data->coin_img)
		return (custom_error("failed to allocate coin_img"), 0);
	if (!data->exit_img)
		return (custom_error("failed to allocate exit_img"), 0);
	return (1);
}

int	set_imgs(t_textur *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "texturs/wall.xpm",
			&data->img_width, &data->img_height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "texturs/floor.xpm",
			&data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "texturs/wplayer.xpm",
			&data->img_width, &data->img_height);
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "texturs/coin.xpm",
			&data->img_width, &data->img_height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "texturs/door.xpm",
			&data->img_width, &data->img_height);
	if (!check_errors(data))
		return (0);
	return (1);
}
