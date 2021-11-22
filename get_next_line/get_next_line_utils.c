/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:15 by hyeo              #+#    #+#             */
/*   Updated: 2021/11/22 16:08:48 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	target;
	int		i;

	i = 0;
	target = (unsigned char)c;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == target)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == target)
		return (&((char *)s)[i]);
	return (0);
}
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	destlen;

	i = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	if (dstsize < destlen)
		return (dstsize + srclen);
	while (src[i] != '\0' && (destlen + i + 1) < dstsize)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (srclen + destlen);
}
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src)
		return (j);
	while (src[j] != '\0')
		j++;
	if (dstsize == 0)
		return (j);
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s2);
	temp = malloc(sizeof(char) * (i + j + 1));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s1, i + 1);
	ft_strlcat(temp + i, s2, j + 1);
	return (temp);
}
