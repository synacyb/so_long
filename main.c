/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:50:17 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/04 01:23:32 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendre_map(t_textur *data, t_map *mdata)
{
	t_sdata var;
	var.i = 0;
	var.j = 0;

	while (mdata->map[var.i])
	{
		var.j = 0;
		while (mdata->map[var.i][var.j] && var.j < mdata->columns)
		{
			if(mdata->map[var.i][var.j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall_img, var.j * 80, var.i * 80);
			if (mdata->map[var.i][var.j] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->floor_img, var.j * 80, var.i * 80);
			if (mdata->map[var.i][var.j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->player_img, var.j * 80, var.i * 80);
			if (mdata->map[var.i][var.j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->exit_img, var.j * 80, var.i * 80);
			if (mdata->map[var.i][var.j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->coin_img, var.j * 80, var.i * 80);
			var.j++;
		}
		var.i++;
	}
	
}

int    init_wind(t_textur  *data, t_map *mdata)
{
	data->img_width;
	data->img_height;
    data->mlx = mlx_init();
    if (!data->mlx)
        return (custom_error("MLX initialization failed", 0));
    data->window = mlx_new_window(data->mlx, mdata->columns * 80, mdata->rows * 80, "so_long");
    if (!data->window)
        return (custom_error("Window creation failed", 0));
	
    data->wall_img = mlx_xpm_file_to_image(data->mlx, "texturs/wall.xpm", &data->img_width, &data->img_height);
    data->floor_img = mlx_xpm_file_to_image(data->mlx, "texturs/floor.xpm", &data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "texturs/wplayer.xpm", &data->img_width, &data->img_height);
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "texturs/coin.xpm", &data->img_width, &data->img_height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "texturs/door.xpm", &data->img_width, &data->img_height);
	if (!data->wall_img)
		perror("Error\n");
	rendre_map(data, mdata);
	mlx_loop(data->mlx);

	return 1;
}

int main(int ac, char **av)
{
	t_map	map;
	t_textur	textur;

	if (ac != 2)
		custom_error("please enter the program name and map", 1);
	if (check_map_name(av[1]) == 0)
		custom_error("map name is invalid!", 1);
	if (check_map(av[1], &map) == 0)
		return (free_matrix(&map), 1);
	if (!init_wind(&textur, &map))
			return(free_matrix(&map), 1);
}