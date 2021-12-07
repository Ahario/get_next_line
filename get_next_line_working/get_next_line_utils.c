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
	char	*temp;
	int			i;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (temp == NULL)
		return (NULL);
	while (s1 != NULL)
	{
		printf("working1\n");
		temp[i] = *s1;
		s1++;
		i++;
		if (!s1)
			break;
	}
	while (*s2)
	{
		printf("working2\n");
		temp[i] = *s2;
		s2++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
