/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:39:37 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/11 20:18:32 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (dest == src || n == 0)
	{
		return (dest);
	}
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *A, char *B)
{
	char	*result;
	size_t	len_a;
	size_t	len_b;

	if (!A)
		return (B);
	if (!B)
		return (A);
	len_a = ft_strlen(A);
	len_b = ft_strlen(B);
	result = malloc(len_a + len_b + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, A, len_a);
	ft_memcpy(result + len_a, B, len_b);
	result[len_a + len_b] = '\0';
	free(A);
	free(B);
	return (result);
}
