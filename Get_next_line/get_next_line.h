/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <hyeo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:16:38 by hyeo              #+#    #+#             */
/*   Updated: 2021/11/21 19:33:59 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
//# include <stdio.h>
typedef struct s_list
{
	unsigned char	*content;
	struct s_list	*next;
}		t_list;

//man


//util

size_t	ft_strlen(char	*str)
char	*ft_strchr(char *s, int c);

#endif
