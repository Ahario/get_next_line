/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <hyeo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:20:28 by hyeo              #+#    #+#             */
/*   Updated: 2021/11/25 13:27:14 by hyeo             ###   ########.fr       */
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
	while (content[i] != '\0' && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	if (content[i] == '\0')
	{
		free(content);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(content) - i + 1));
	if (!temp)
		return (NULL);
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
		return (NULL);
	while (content[j] != '\0')
	{
		if (content[j] == '\n')
		{
			temp[j] = '\n';
			j++;
			break;
		}
		temp[j] = content[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*add_content(int fd, char *content)
{
	int		i;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;
	
	i = read(fd, buff, BUFFER_SIZE);
	if (i <= 0)
		return (NULL);
	buff[i] = '\0';
	temp = ft_strjoin(content, buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*temp;
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0)	
		return (0);
	if (!content && !temp)
		content = add_content(fd, content);
	if (!content)
	{
		temp = NULL;
		free(temp);
		return (NULL);
	}
	temp = one_line(content);
	content = move_one_line(content);
	return (temp);
}
