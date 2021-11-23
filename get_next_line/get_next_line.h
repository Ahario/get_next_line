/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <hyeo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:16:38 by hyeo              #+#    #+#             */
/*   Updated: 2021/11/23 13:33:55 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
//main
char	*move_one_line(char	*content);
char	*one_line(char	*content);
char	*add_content(int fd, char *content);
char	*get_next_line(int fd);

//util
unsigned int	ft_strlen(const char	*str);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE

#endif
