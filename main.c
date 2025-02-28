/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:50:17 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/27 15:51:09 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		custom_error("please enter the program name and map", 1);
	if (check_map_name(av[1]) == 0)
		custom_error("map name is invalid!", 1);
	if (check_map(av[1], &map) == 0)
		return (free_matrix(&map), 1);
	
	printf("valid map");
	
}