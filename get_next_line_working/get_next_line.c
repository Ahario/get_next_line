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
	while (content[i + j] != '\0')
		j++;
	temp = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (content[i + j] != '\0')
	{
		temp[j] = content[i + j];
		j++;
	}
	temp[j] = '\0';
	return (temp);

}
char	*get_one_line(char *content)
{
	int			i;
	int			j;
	char	*temp;	

	i = 0;
	j = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	while (content[j] != '\n' && content[j] != '\0')
	{
		temp[j] = content[j];
		j++;
		if (content[j] == '\n' || content[j] == '\0')
		{
			if (content[j] == '\n')
			{
				temp[j] = '\n';
				j++;
			}
			break;
		}
	}
	temp[j] = '\0';
	return (temp);
}

char	*add_content(int fd, char *content)
{
	int			i;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	i = 1;
	while (!ft_strchr(content, '\n') && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		content = ft_strjoin(content, buff);
		printf("%s\n", content);
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
	printf("%s\n", content);
	content = move_one_line(content);
	return (temp);
}
