/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/02/25 19:02:41 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			bytes_read;
	static char	*stash;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	stash = malloc(bytes_read);
	if (bytes_read == -1 || bytes_read == 0)
		return (NULL);
	line = malloc((bytes_read + 1) * sizeof(char));
	if (!line)
		return (NULL);
	if (bytes_read > 0)
	{
		ft_memcpy(line, buffer, bytes_read);
		line[bytes_read] = '\0';
	}
	return (line);
}
