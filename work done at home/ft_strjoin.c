/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:57:57 by thcardos          #+#    #+#             */
/*   Updated: 2025/12/05 16:48:01 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *A, char const *B)
{
	char	*C;
	size_t	both_len;
	size_t	i;

	if (!A || !B)
		return (NULL);
	both_len = (ft_strlen(A) + ft_strlen(B));
	C = malloc(both_len + 1);
	if (!C)
		return (NULL);
	i = 0;
	while (i < ft_strlen(A))
	{
		C[i] = A[0 + i];
		i++;
	}
	while ((i - ft_strlen(A)) < ft_strlen(B))
	{
		C[i] = B[i - ft_strlen(A)];
		i++;
	}
	C[ft_strlen(A) + ft_strlen(B)] = '\0';
	free(A);
	return (C);
}
