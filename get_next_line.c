/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/09 18:28:58 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*A;
	char		buffer[BUFFER_SIZE];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	A = malloc((bytes_read + 1) * sizeof(char));
	if (!A)
		free (A);
		return (NULL);
	find_new_line(A, buffer, bytes_read);
	return (A);
}
char *find_new_line(char *A, char *buffer, int bytes_read)
{
	char	*B;
	int	b_size;
	
	if (!A)
		free(A);
		return (NULL);
	if (!ft_strchr(A, '\n'))
	{
		read_to_B (B);
		A = ft_strjoin(A, B);//haciendo un join (dentro liberamos A)
		//join retorna lo concatenado y lo mete en A
		free(B);
	}
	if (ft_strchr(A, '\n'))
	{
		
	}
}
char *read_to_B(char *B)
