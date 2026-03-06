/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:39:37 by thcardos          #+#    #+#             */
/*   Updated: 2026/03/03 20:50:33 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
}*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
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
void	*ft_memcpy(void *dest, const void *src, size_t n)
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
char	*ft_strdup(const char *s)
{
	size_t	len;
	int		i;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	both_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	both_len = (ft_strlen(s1) + ft_strlen(s2));
	s3 = malloc(both_len + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[0 + i];
		i++;
	}
	while ((i - ft_strlen(s1)) < ft_strlen(s2))
	{
		s3[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s3);
}
