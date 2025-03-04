/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:27:18 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/04 19:34:38 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    set_data(t_vchar *elements)
{
    elements->c = 0;
    elements->e = 0;
    elements->n = 0;
    elements->p = 0;
}
void    check_elemet(t_vchar *elements, char c)
{
    if(c == 'P')
        elements->p++;
    else if(c == 'E')
        elements->e++;
    else if(c == 'C')
        elements->c++;
}
int validate_map_elements(t_map *data)
{
    t_sdata s_data;
    t_vchar v_element;
    char c;

    s_data.i = 0;
    s_data.j = 0;
    set_data(&v_element);
    while (data->copy_map[s_data.i])
    {
        s_data.j = 0;
        while (data->copy_map[s_data.i][s_data.j] && s_data.j < data->columns)
        {
            c = data->copy_map[s_data.i][s_data.j];
            check_elemet(&v_element, c);
            s_data.j++;
        }
        s_data.i++;
    }
    data->c = v_element.c;
    data->check_c = 0;
    if(!(v_element.c >= 1 && v_element.p == 1 && v_element.e == 1))
        return 0;
    return 1;
}
