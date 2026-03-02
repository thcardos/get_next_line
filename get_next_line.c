/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/02 20:41:25 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash, char *newline_pos)
{
	size_t	line_len;
	char	*line;

	line_len = (newline_pos - stash) + 1;
	line = malloc((line_len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, line_len);
	line[line_len] = '\0';
	return (line);
}
static char	*update_stash(char *stash, char *newline_pos)
{
	size_t	rest_len;
	char	*new_stash;

	if (*(newline_pos + 1) == '\0')
		return (free(stash), NULL);
	rest_len = ft_strlen(newline_pos + 1);
	new_stash = malloc((rest_len + 1) * sizeof(char));
	if (!new_stash)
		return (free(stash), NULL);
	ft_memcpy(new_stash, newline_pos + 1, rest_len);
	new_stash[rest_len] = '\0';
	return (free(stash), new_stash);
}
static char	*concat_to_stash(char *stash, char *buffer, int bytes_read)
{
	char	*new_stash;
	size_t	stash_len;
	size_t	total_len;

	buffer[bytes_read] = '\0';
	if (stash != NULL)
	{
		stash_len = ft_strlen(stash);
		total_len = stash_len + bytes_read;
		new_stash = malloc((total_len + 1) * sizeof(char));
		if (!new_stash)
			return (free(stash), NULL);
		ft_memcpy(new_stash, stash, stash_len);
		ft_memcpy(new_stash + stash_len, buffer, bytes_read);
		new_stash[total_len] = '\0';
		return (free(stash), new_stash);
	}
	else
	{
		if (!(stash = malloc(bytes_read + 1)))
			return (NULL);
		ft_memcpy(stash, buffer, bytes_read);
		stash[bytes_read] = '\0';
		return (stash);
	}
}
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	char		*newline_pos;
    char buffer[BUFFER_SIZE];
    int bytes_read;

	if (stash != NULL)
	{
		if ((newline_pos = ft_strchr(stash, '\n')) != NULL)
		{
			if (!(line = extract_line(stash, newline_pos)))
			{
				free(stash);
				stash = NULL;
				return (NULL);
			}
			stash = update_stash(stash, newline_pos);
			return (line);
		}
	}
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
		{
			if (stash != NULL)
			{
				return (stash);
			}
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash = concat_to_stash(stash, buffer, bytes_read);
        if (!stash)
            return (NULL);
        if ((newline_pos = ft_strchr(stash, '\n')) != NULL)
        {
            line = extract_line(stash, newline_pos);
            stash = update_stash(stash, newline_pos);
            return (line);
        }
        /* Si no hay \n, continuar bucle */
    }
}
