/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:15 by hyeo              #+#    #+#             */
/*   Updated: 2021/11/25 14:06:16 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
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
	
	if (!s1)
		i = 0;
	else
		i = ft_strlen(s1);
	j = ft_strlen(s2);
	temp = malloc(sizeof(char) * (i + j + 1));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s1, i + 1);
	ft_strlcat(temp + i, s2, j + 1);
	return (temp);
}
