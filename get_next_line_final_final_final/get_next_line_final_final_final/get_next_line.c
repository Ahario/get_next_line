/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <hyeo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:20:28 by hyeo              #+#    #+#             */
/*   Updated: 2021/12/07 15:48:51 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_one_line(char	*content)
{
	int			i;
	int			j;
	char	*temp;

	i = 0;
	j = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] == '\0')
	{
		free(content);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(content) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (content[i + j])
	{
		temp[j] = content[i + j];
		j++;
	}
	temp[j] = '\0';
	free(content);
	return (temp); 
}
char	*get_one_line(char *content)
{
	int			i;
	int			j;
	char	*temp;	

	i = 0;
	j = 0;
	if (!content[i])
		return (NULL);
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	while (content[j] != '\n' && content[j] != '\0')
	{
		temp[j] = content[j];
		j++;
	}
	if (content[j] == '\n')
	{
		temp[j] = '\n';
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*add_content(int fd, char *content)
{
	int			i;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(content, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		content = ft_strjoin(content, buff);
	}
	free(buff);
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
	temp = get_one_line(content);
	content = move_one_line(content);
	return (temp);
}
 