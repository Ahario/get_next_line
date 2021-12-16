/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:15 by hyeo              #+#    #+#             */
/*   Updated: 2021/12/07 15:54:04 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	char	target;
	int		i;

	i = 0;
	target = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == target)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == target) 
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[++j] != '\0')
		str[i++] = s1[j];
	j = -1;
	while (s2[++j] != '\0')
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	return (str);
}
