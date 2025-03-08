/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:32:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/08 10:30:03 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_rows(int fd)
{
	int		len;
	char	*res;

	len = 0;
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		len++;
		free(res);
	}
	close(fd);
	return (len);
}

void	creat_matrix(int fd, t_map *data)
{
	int		index;
	char	*res;

	data->copy_map = malloc((data->rows + 1) * sizeof(char *));
	if (!data->copy_map)
		return ;
	index = 0;
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

char	*ft_strcpy(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = malloc(ft_strlen(s1) + 1);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	**ft_strcpymap(char **map, int length)
{
	char	**cpymap;
	int		i;

	cpymap = malloc(sizeof(char *) * (length + 1));
	i = 0;
	while (i < length)
	{
		cpymap[i] = ft_strcpy(map[i]);
		i++;
	}
	cpymap[i] = NULL;
	return (cpymap);
}

int	check_map(char *file_name, t_map *data)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		custom_error("path is not exist!\n");
		return (0);
	}
	data->rows = count_rows(fd);
	fd = open(file_name, O_RDONLY);
	creat_matrix(fd, data);
	data->map = ft_strcpymap(data->copy_map, data->rows);
	data->columns = ft_strlen(data->copy_map[0]) - 1;
	if (data->columns == -1)
		return (custom_error("map is empty!"), 0);
	if (check_all_cases(data) == 0)
		return (0);
	return (1);
}
