/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:42:52 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/27 13:52:40 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*src;
// 	size_t	i;
// 	char	*str;

// 	if (s == NULL)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len + start > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	src = (char *)s + start;
// 	i = 0;
// 	str = malloc((len + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		*str = *src;
// 		str++;
// 		src++;
// 		i++;
// 	}
// 	*str = '\0';
// 	str = str - i;
// 	return (str);
// }

char	*find_line(int fd, char *str, char *buffer)
{
	ssize_t		n;
	char		*tmp;
	char		*check_new_line;

	while (1)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		else if (n == 0)
			break ;
		buffer[n] = '\0';
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		check_new_line = ft_strchr(buffer, '\n');
		if (check_new_line)
			break ;
	}
	return (str);
}

char	*find_next_line(char *str)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	tmp = ft_substr(str, i + 1, len - i);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	str[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save_str;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = find_line(fd, save_str, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	save_str = find_next_line(line);
	return (line);
}
