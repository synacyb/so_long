/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:50:17 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/08 11:17:27 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *data)
{
	if (data->data->coin_img)
		mlx_destroy_image(data->data->mlx, data->data->coin_img);
	if (data->data->exit_img)
		mlx_destroy_image(data->data->mlx, data->data->exit_img);
	if (data->data->floor_img)
		mlx_destroy_image(data->data->mlx, data->data->floor_img);
	if (data->data->player_img)
		mlx_destroy_image(data->data->mlx, data->data->player_img);
	if (data->data->wall_img)
		mlx_destroy_image(data->data->mlx, data->data->wall_img);
	if (data->data->win)
		mlx_destroy_window(data->data->mlx, data->data->win);
	if (data->data->mlx)
		mlx_destroy_display(data->data->mlx);
	free_matrix(data->copy_map);
	free_matrix(data->map);
	free(data->data->mlx);
	exit(0);
}

void	rendre_map(t_map *mdata)
{
	t_sdata	var;

	var.i = 0;
	var.j = 0;
	while (var.i < mdata->rows)
	{
		var.j = 0;
		while (var.j < mdata->columns)
		{
			put_img_to_window(mdata, &var);
			var.j++;
		}
		var.i++;
	}
}

int	init_wind(t_textur *data, t_map *mdata)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (custom_error("MLX initialization failed"), 0);
	data->win = mlx_new_window(data->mlx, mdata->columns * 80,
			mdata->rows * 80, "so_long");
	if (!data->win)
		return (custom_error("Window creation failed"), 0);
	if (!set_imgs(data))
		close_window(mdata);
	rendre_map(mdata);
	mlx_key_hook(data->win, update_map, mdata);
	mlx_hook(data->win, 17, 0, close_window, mdata);
	mlx_loop(data->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_map		map;
	t_textur	textur;

	map.moves = 0;
	map.data = &textur;
	ft_bzero(&map, sizeof(t_map *));
	ft_bzero(&textur, sizeof(t_textur *));
	set_map(&map);
	if (ac != 2)
		return (custom_error("please enter the program name and map"), 1);
	if (check_map_name(av[1]) == 0)
		return (custom_error("map name is invalid!"), 1);
	if (check_map(av[1], &map) == 0)
	{
		(free_matrix(map.copy_map), free_matrix(map.map));
		return (1);
	}
	if (!init_wind(&textur, &map))
	{
		(free_matrix(map.copy_map), free_matrix(map.map));
		return (1);
	}
}
