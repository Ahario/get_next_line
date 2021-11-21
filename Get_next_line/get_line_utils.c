/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <hyeo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:57:58 by hyeo              #+#    #+#             */
/*   Updated: 2021/11/21 19:11:11 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
	size_t	i;

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

