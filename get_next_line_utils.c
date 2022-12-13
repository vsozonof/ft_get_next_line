/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:05 by vsozonof          #+#    #+#             */
/*   Updated: 2022/12/13 11:01:29 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!(s1) && !(s2))
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(sizeof(char) * len + 1);
	if (!(str))
		return (NULL);
	len = -1;
	while (++len < ft_strlen(s1))
		str[len] = s1[len];
	i = 0;
	while (len < (ft_strlen(s2) + ft_strlen(s1)))
	{
		str[len] = s2[i];
		len++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!(str))
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_find_newline(char *s)
{
	int	i;

	i = -1;
	if (!(s))
		return (0);
	while (s[++i])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

// int	ft_len_checker(const char *s, unsigned int start, size_t len)
// {
// 	size_t	i;

// 	i = -1;
// 	while (++i < len && s[start])
// 		start++;
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t		i;
// 	char		*str;

// 	if (!(s) || len == 0 || start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	len = ft_len_checker(s, start, len);
// 	str = malloc(sizeof(char) * len + 1);
// 	if (!(str))
// 		return (NULL);
// 	i = -1;
// 	while (++i < len && (start + i) < ft_strlen(s))
// 		str[i] = s[start + i];
// 	str[i] = '\0';
// 	return (str);
// }
