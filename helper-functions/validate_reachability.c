/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_reachability.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:38:27 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/01 09:48:21 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int validate_reachability(char **tab)
{
    t_sdata data;

    data.i = 0;
    data.len = ft_strlen(tab[0]) - 1;
    while (tab[data.i])
    {
        data.j = 0;
        while (tab[data.i][data.j] && data.j < data.len)
        {
            if(tab[data.i][data.j] != '1' && tab[data.i][data.j] != 'F')
                return (0);
            data.j++;
        }
        data.i++;
    }
    return (1);
}