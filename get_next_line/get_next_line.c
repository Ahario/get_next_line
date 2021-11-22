/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <hyeo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:20:28 by hyeo              #+#    #+#             */
/*   Updated: 2021/11/22 17:23:55 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_one_line(char *content)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (0);
	while (content[j + i] != '\0')
	{
		temp[j] = content[j + i];
		j++;
	}
	free(content);
	temp[j] = '\0';
	return (temp);
}

char	*one_line(char	*content)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (0);
	while (content[j] != '\n' && content[j] != '\0')
	{
		temp[j] = content[j];
		j++;
		if (content[j] == '\n')
		{
			temp[j] = '\n';
			j++;
			break;
		}
	}
	temp[j] = '\0';
	return (temp);
}

char	*add_content(int fd, char *content)
{
	int		i;
	char	buff[BUFFER_SIZE];
	char	*temp;

	i = read(fd, buff, BUFFER_SIZE);
	if (ft_strchr(content, '\n') == 0 && !content)
	{
		temp = ft_strjoin(content, buff);
		temp[i] = '\0';
		return (temp);
	}
	return (content);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	content = add_content(fd, content);
	if (!content)
		return (NULL);
	temp = one_line(content);
	content = move_one_line(content);
	return (temp);
}
