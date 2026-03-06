/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/06 18:47:38 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*A;
	char		buffer[BUFFER_SIZE];
	int			bytes_read;
	char	*B;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	A = malloc((bytes_read + 1) * sizeof(char));
	if (!A)
		return (NULL);
	find_new_line(A);
	return (A);
}
char *concat_to_stash(char *A, char *buffer, int bytes_read)
{
	if (!A)
		return (NULL);
	if (!ft_strchr(A, '\n'))
	{
		//llamar a funcion que llena B
		//concatenar A y B 
		//haciendo un join (dentro liberamos A)
		//join retorna lo concatenado y lo mete en A
	}
	else //si hay salto de linea y hay más texto después
	{
		//Concatena A y B(NULL) en C
	}
}
