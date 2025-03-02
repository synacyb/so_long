/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:50:17 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/02 15:15:22 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    init_wind(t_textur  *data, int length, int width)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        return (custom_error("MLX initialization failed", 0));
    data->window = mlx_new_window(data->mlx, width * 40, length * 40, "so_long");
    if (!data->window)
        return (custom_error("Window creation failed", 0));
	mlx_loop(data->mlx);
    data->wall_img = mlx_xpm_file_to_image(data->mlx, "../wall_xpm/wall.xpm", NULL, NULL);
    data->floor_img = mlx_xpm_file_to_image(data->mlx, "../floor/floor.xpm", NULL, NULL);
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
	
		if (!init_wind(&textur, map.rows, map.columns))
			return(free_matrix(&map), 1);
		
}