/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:32:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/28 10:27:26 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_rows(int fd)
{
	int	len;
	len = 0;
	char *res;
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		len++;
		free(res);
	}
	return len;
}

void	creat_matrix(int fd, t_map *data)
{
	data->copy_map = malloc((data->rows + 1) * sizeof(char *));
	if (!data->copy_map)
		return;
	
	int index = 0;
	char *res;
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		data->copy_map[index] = res;
		index++;
	}
	data->copy_map[index] = NULL;
	close(fd);
}

int	check_map(char *file_name, t_map *data)
{
	int fd = open(file_name, O_RDONLY);
	data->rows = count_rows(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	creat_matrix(fd, data);
	data->columns = ft_strlen(data->copy_map[0]) - 1;
	if(data->columns == -1)
		return (perror("map is empty!"), 0);
	if (check_all_cases(data) == 0)
		return(0); 
	return(1);
}