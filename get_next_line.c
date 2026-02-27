/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:38:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/02/27 20:00:10 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
char	*get_next_line(int fd)
{
	static char *stash = NULL; // Inicializar a NULL (solo la primera vez)
	char	*line = NULL; //Lo que devolveremos
	int *newline_pos; // Para guardar el retorno de ft_strchr
	size_t line_len;  // Para calcular longitud de la línea
	size_t	rest_len; // Longitud del resto en stash
	char *new_bstash = NULL; //Para el nuevo stash temporal

	if (stash != NULL)
	{
		newline_pos = ft_strchr(stash, '\n'); // Busca '\n' en stash y gusrda el retorno en newline
		
		if (newline_pos != NULL) // Si se ha encontrado \n
		{
			line_len = (newline_pos - stash) + 1; // calcula longirtud de la linea (+1 para incluir el \n)
			line = malloc((line_len + 1) * sizeof(char)); // Reserva memoria para line
			if (!line)
				return (NULL);
			if (line_len == -1 || bytes_read == 0)
				return (NULL);
			if (line_len > 0)
			{
				ft_memcpy(line, stash, line_len); //Copia line_len bytes desde stash a line
				line[line_len] = '\0'; //Añade el terminador
			}
			return (line);
			if((newline_pos + 1) != NULL) //Si hay algo despues del \n
				strlen(stash) - line_len; // 1. Calcula longitud del resto
				 // 2. malloc nuevo buffer para el resto
				// 3. Copia los caracteres del resto al nuevo buffer
				free(stash); // 4. Libera el antiguo
				// 5. stash = nuevo_buffer
	}
	line_len = read(fd, buffer, BUFFER_SIZE);
	stash = malloc(line_len);
		}	
		
	// procesar stash:
	// si encuentro \n en el stash, devolver linea hasta ahí
	// guardo lo demás en el stash(actualizo)
	// si no encuentro \n leo más con read
	// concateno con el stash
}
// llamar a read()

/*if (line_len == -1 || bytes_read == 0)
		return (NULL);
	line = malloc((line_len + 1) * sizeof(char));
	if (line_len > 0)
	{
		ft_memcpy(line, buffer, line_len);
		line[line_len] = '\0';
	}
	return (line);*/

/*
┌─────────────────────────────────────────────────────┐
│  if (stash != NULL)                                 │
│  {                                                  │
│      newline_pos = ft_strchr(stash, '\n');          │
│                                                     │
│      if (newline_pos != NULL)  ← ENCONTRÉ \n        │
│      {                                              │
│          1. Calcular line_len                       │
│          2. malloc para line                        │
│          3. Verificar malloc                        │
│          4. COPIAR datos de stash a line            │
│          5. Añadir '\0' a line                      │
│          6. ACTUALIZAR stash con el resto           │ ← ¡FALTA!
│          7. return (line);                          │ ← ¡FALTA!
│      }                                              │
│      // Si NO hay \n: NO hacer nada, continuar      │
│  }                                                  │
│                                                     │
│  // Solo llegas aquí si NO encontraste \n en stash  │
│  bytes_read = read(fd, buffer, BUFFER_SIZE);        │
│  // ... continuar con lógica de read()              │
└─────────────────────────────────────────────────────┘
*/