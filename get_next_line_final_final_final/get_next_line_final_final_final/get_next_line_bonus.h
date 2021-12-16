/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <hyeo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:16:38 by hyeo              #+#    #+#             */
/*   Updated: 2021/12/07 14:58:28 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE

# endif

unsigned int	ft_strlen(const char *s);
char			*move_one_line(char	*content);
char			*get_one_line(char	*content);
char			*add_content(int fd, char *content);
char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
#endif
