/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:54:01 by vsozonof          #+#    #+#             */
/*   Updated: 2023/01/30 08:03:40 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_and_fill_stash(int fd, char *stash);
char	*extract_from_stash(char *stash);
char	*get_line(char *stash);
char	*ft_strjoin(char const *s1, char const *s2);
char	*free_and_join_stash(char *stash, char *tmp);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_find_newline(char *s);
char	*ft_strdup(const char *s);

#endif