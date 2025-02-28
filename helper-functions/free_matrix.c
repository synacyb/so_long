/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:24:31 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/27 14:47:45 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    free_matrix(t_map *data)
{
    int i = 0;
    while (i< data->rows)
    {
        free(data->copy_map[i]);
        i++;
    }
    free(data->copy_map);
}