/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_reachability.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:38:27 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/05 14:14:31 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int validate_reachability(char **tab)
{
    t_sdata data;

    data.i = 0;
    while (tab[data.i])
    {
        data.j = 0;
        while (tab[data.i][data.j])
        {
            if(tab[data.i][data.j] == 'C')
                return (0);
            data.j++;
        }
        data.i++;
    }
    return (1);
}

int validate_reachability2(char **tab)
{
    t_sdata data;

    data.i = 0;
    while (tab[data.i])
    {
        data.j = 0;
        while (tab[data.i][data.j])
        {
            if(tab[data.i][data.j] == 'E' || tab[data.i][data.j] == 'C')
                return (0);
            data.j++;
        }
        data.i++;
    }
    return (1);
}