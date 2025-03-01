/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pose_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:04:31 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/01 09:15:19 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    get_pos_of_player(char **tab, t_sdata *data)
{
    data->i = 0;
    data->j = 0;
    data->len = ft_strlen(tab[0]) - 1;
    while (tab[data->i])
    {
        data->j = 0;
        while (tab[data->i][data->j] && data->j < data->len)
        {
            if (tab[data->i][data->j] == 'P')
            {
                data->pos_y = data->i;
                data->pos_x = data->j;
            }
            data->j++;
        }
        data->i++;
    }
}