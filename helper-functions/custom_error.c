/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:50:11 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/08 10:31:33 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	custom_error(char *msg)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", 2);
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
}
