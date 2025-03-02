/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:32:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/02 13:07:09 by ayadouay         ###   ########.fr       */
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
char *ft_strcpy(char *s1)
{
	int i = 0;
	char *s2;
	s2 = malloc(ft_strlen(s1) + 1);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return s2;
}
char **ft_strcpymap(char **map, int lint, int colums)
{
	char **cpymap;
	cpymap =  malloc(sizeof(char*) * (lint + 1));
	int i = 0;
	int j;
	while (i < lint)
	{
		cpymap[i] = ft_strcpy(map[i]);
		i++;
	}
	return (cpymap);
}
int	check_map(char *file_name, t_map *data)
{
	int fd = open(file_name, O_RDONLY);
	data->rows = count_rows(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	creat_matrix(fd, data);
	data->map = ft_strcpymap(data->copy_map, data->rows, data->columns);
	data->columns = ft_strlen(data->copy_map[0]) - 1;
	if(data->columns == -1)
		return (perror("map is empty!"), 0);
	if (check_all_cases(data) == 0)
		return(0);
	return(1);
}