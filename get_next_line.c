/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/11 22:27:56 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_to_b(char *buffer, int fd)
{
	int		bytes_read;
	char	*new_buf;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	new_buf = malloc(bytes_read + 1);
	if (!new_buf)
		return (NULL);
	ft_memcpy(new_buf, buffer, bytes_read);
	new_buf[bytes_read] = '\0';
	return (new_buf);
}

char	*handle_newline_case(char *A, char **stash, char *newline_pos)
{
	size_t	line_len;
	size_t	rest_len;
	char	*line;

	line_len = (newline_pos - A) + 1;
	line = malloc(line_len + 1);
	if (!line)
		return (free(A), *stash = NULL, NULL);
	ft_memcpy(line, A, line_len);
	line[line_len] = '\0';
	rest_len = ft_strlen(newline_pos + 1);
	if (rest_len > 0)
	{
		*stash = malloc(rest_len + 1);
		if (!*stash)
			return (free(A), free(line), NULL);
		ft_memcpy(*stash, newline_pos + 1, rest_len);
		(*stash)[rest_len] = '\0';
	}
	else
		*stash = NULL;
	return (free(A), line);
}

char	*split_string(char *A, char **stash)
{
	char	*newline_pos;
	char	*line;

	newline_pos = ft_strchr(A, '\n');
	if (!newline_pos)
	{
		line = malloc(ft_strlen(A) + 1);
		if (!line)
			return (free(A), *stash = NULL, NULL);
		ft_memcpy(line, A, ft_strlen(A) + 1);
		free(A);
		*stash = NULL;
		return (line);
	}
	return (handle_newline_case(A, stash, newline_pos));
}

char	*find_new_line(char *A, char *buffer, int fd)
{
	char	*b;

	while (!ft_strchr(A, '\n'))
	{
		b = read_to_b(buffer, fd);
		if (!b)
			break ;
		A = ft_strjoin(A, b);
		if (!A)
			return (NULL);
	}
	return (A);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	char		*newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (stash != NULL)
	{
		newline_pos = ft_strchr(stash, '\n');
		if (newline_pos != NULL)
		{
			free(buffer);
			return (split_string(stash, &stash));
		}
	}
	stash = find_new_line(stash, buffer, fd);
	free(buffer);
	if (!stash)
		return (NULL);
	line = split_string(stash, &stash);
	return (line);
}
