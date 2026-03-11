/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:50:03 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/11 22:28:10 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (line)
		{
			printf("Linea %d: %s\n", i + 1, line);
			free(line);
			i++;
		}
		else
			printf("LINE: (null)\n");
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
/*cc -g -Wall -Wextra -Werror -fsanitize=address
	-D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c main.c && ./a.out
 */
