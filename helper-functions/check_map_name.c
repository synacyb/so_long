/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:24:47 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/08 11:12:09 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 4 && str[len - 1] == 'r' && str[len - 2] == 'e'
		&& str[len - 3] == 'b' && str[len - 4] == '.' && str[len - 5] != '/')
		return (1);
	return (0);
}
