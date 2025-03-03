/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:26:49 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/03 09:48:57 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_rectangular(t_map *data)
{
    t_sdata s_data;

    s_data.i = 1;
    while (data->copy_map[s_data.i])
    {
        s_data.j = 0;
        s_data.j = effective_length(data->copy_map[s_data.i]);
        if (data->columns != s_data.j)
            return 0;
        s_data.i++;
    }
    return 1;
}
int is_closed_by_walls(t_map *data)
{
    t_sdata s_data;

    s_data.i = 0;
    s_data.j = 0;
    //check the first row!
    while (data->copy_map[0][s_data.j] && s_data.j < data->columns)
    {
        if (data->copy_map[0][s_data.j] != '1')
            return 0;
        s_data.j++;
    }
    s_data.j = 0;
    //check the last row! 
    while (data->copy_map[data->rows - 1][s_data.j] && s_data.j < data->columns)
    {
        if (data->copy_map[data->rows - 1][s_data.j] != '1')
            return 0;
        s_data.j++;
    }
    //check the first colum!
    while(s_data.i < data->rows)
    {
        if (data->copy_map[s_data.i][0] != '1')
            return 0;
        s_data.i++;
    }
    s_data.i = 0;
    //check the last colum!
    while(s_data.i < data->rows)
    {
        if (data->copy_map[s_data.i][data->columns - 1] != '1')
            return 0;
        s_data.i++;
    }
    return 1;
}
int check_valid_character(t_map *data)
{
    t_sdata s_data;
    char c;

    s_data.i = 0;
    s_data.j = 0;
    while (data->copy_map[s_data.i])
    {
        s_data.j = 0;
        while (data->copy_map[s_data.i][s_data.j] && s_data.j < data->columns)
        {
            c = data->copy_map[s_data.i][s_data.j];
            if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
                return 0;
            s_data.j++;
        }
        s_data.i++;
    }
    if(!validate_map_elements(data))
        return 0;
    return 1;
}
int check_all_cases(t_map *data)
{
    t_sdata info;

    if(!is_rectangular(data))
        return (perror("this map is not rectangular\n"), 0);
    if(!is_closed_by_walls(data))
        return (perror("Error this walls!"), 0);
    if(!check_valid_character(data))
        return (perror("invalid character in the map"), 0);
    get_pos_of_player(data->copy_map, &info);
    floodfill(data->copy_map, info.pos_x, info.pos_y, data);
    if(!validate_reachability(data->copy_map))
        return (perror("the map is not reachable !"), 0);
    
    return (1);
}
