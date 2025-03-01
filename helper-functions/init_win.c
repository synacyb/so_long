/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:52:40 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/01 15:57:03 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    *init_win(t_textur  *data, int colums, int rows)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        return NULL;
    
}