/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effective_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:36:57 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/05 09:58:11 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	effective_length(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		return (len - 1);
	return (len);
}
