/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:50:11 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/22 16:50:12 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int custom_error(char *msg, int exit_code)
{
    int i = 0;
    while (msg[i])
    {
        write(1, &msg[i], 1);
        i++;
    }
    exit(exit_code);
}