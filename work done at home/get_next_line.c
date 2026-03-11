/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/10 15:53:51 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_to_B(char *B, char *buffer, int fd)
{
	int			bytes_read;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	B = malloc((bytes_read + 1) * sizeof(char));
	if (!B)
		return (NULL);
	ft_memcpy(B, buffer, bytes_read);
	B[bytes_read] = '\0';
	return (B);
}
char *funcionauxiliarparaextraer()
{
	//extraer desde inicio de A hasta \n 
	//meter el resto en B
	//return A
	//free A
	//A = B
	//free B
}
char *find_new_line(char *A, char *buffer, int fd)
{
	char	*B;

	B = NULL;
	
	if (!A)
		return (NULL);
	while (!ft_strchr(A, '\n'))
	{
		B = read_to_B (B, buffer, fd);
		if (!B)
			break;
		A = ft_strjoin(A, B);
		free(B);
		B = NULL;
	}
	if (ft_strchr(A, '\n'))
	{
		funcionauxiliarparaextraer();
	}
	return(A);
}
char	*get_next_line(int fd)
{
	static char		*A;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		return (NULL);
	}
	A = malloc((bytes_read + 1) * sizeof(char));
	if (!A)
	{
		free (A);
		return (NULL);
	}
	A = ft_memcpy(A, buffer, bytes_read);
	A = find_new_line(A, buffer, fd);
	return (A);
}
