/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:31:20 by lecavall          #+#    #+#             */
/*   Updated: 2026/03/05 10:41:00 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*left_c;
	char		*line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(left_c);
		left_c = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_c, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = set_line(line);
	if (!left_c && (*line) == 0)
		return (free(line), NULL);
	return (line);
}

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	char		*tmp;
	long long	b_read;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(left_c), NULL);
		if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*set_line(char *line)
{
	char	*left_c;
	char	*tmp;

	tmp = line;
	tmp = ft_strchr(line, '\n');
	if (!tmp)
	{
		return (NULL);
	}
	left_c = ft_strdup(&tmp[1]);
	if (!left_c)
	{
		free (left_c);
		left_c = NULL;
	}
	tmp[1] = 0;
	return (left_c);
}
