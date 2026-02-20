/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/02/20 18:28:50 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    int bytes_read = read(fd, buffer, BUFFER_SIZE);  // Guarda el retorno

    if (bytes_read == -1)
        return (NULL);  // Error
    if (bytes_read == 0)
        return (NULL);  // EOF

// Si llega aquí, leyó datos correctamente
return (NULL); 
}


