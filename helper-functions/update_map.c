/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:42:43 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/04 11:32:53 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// void    finish_game(t_map *data)
// {
//     if (data->map[data->new_y][data->new_x] != 'E')
// }
int    update_map(int keycode, t_map *data)
{
    data->new_x = data->pos_x;
    data->new_y = data->pos_y;

    if (keycode == 65307)
        exit(0);
    if (keycode == 0xff51 || keycode == 97)
        data->new_x -= 1;
    if (keycode == 0xff52 || keycode == 119)
        data->new_y -= 1;
    if (keycode == 0xff53 || keycode == 100)
        data->new_x += 1;
    if (keycode == 0xff54 || keycode == 115)
        data->new_y += 1;

    if (data->map[data->new_y][data->new_x] != '1')
    {
        data->map[data->pos_y][data->pos_x] = '0';
        data->map[data->new_y][data->new_x] = 'P';
        data->pos_x = data->new_x;
        data->pos_y = data->new_y;
        rendre_map(data->data, data);
    }
    return 0;
}
