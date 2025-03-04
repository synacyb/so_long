/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pose_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:04:31 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/04 10:06:59 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    get_pos_of_player(t_map *mdata, t_sdata *data)
{
    data->i = 0;
    data->j = 0;
    data->len = ft_strlen(mdata->copy_map[0]) - 1;
    while (mdata->copy_map[data->i])
    {
        data->j = 0;
        while (mdata->copy_map[data->i][data->j] && data->j < data->len)
        {
            if (mdata->copy_map[data->i][data->j] == 'P')
            {
                data->pos_y = data->i;
                data->pos_x = data->j;
            }
            data->j++;
        }
        data->i++;
    }
    mdata->pos_y = data->pos_y;
    mdata->pos_x = data->pos_x;
}
