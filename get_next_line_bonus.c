/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:00 by vsozonof          #+#    #+#             */
/*   Updated: 2023/01/30 08:26:52 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stash[FOPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash[fd] = read_and_fill_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = extract_from_stash(stash[fd]);
	return (line);
}

char	*read_and_fill_stash(int fd, char *stash)
{
	char		*tmp;
	int			counter;

	counter = 1;
	while (ft_find_newline(stash) == -1 && counter != 0)
	{
		tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
		counter = read(fd, tmp, BUFFER_SIZE);
		if (counter == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[counter] = '\0';
		stash = free_and_join_stash(stash, tmp);
		free(tmp);
	}
	return (stash);
}

char	*free_and_join_stash(char *stash, char *tmp)
{
	char	*new_stash;

	new_stash = ft_strjoin(stash, tmp);
	free (stash);
	return (new_stash);
}

char	*extract_from_stash(char *stash)
{
	char	*new_stash;
	int		len;

	len = (ft_strlen(stash) - ft_find_newline(stash));
	if (!stash || ft_find_newline(stash) == -1)
	{
		free(stash);
		return (NULL);
	}
	else
		new_stash = ft_substr(stash, (ft_find_newline(stash) + 1), len);
	free(stash);
	return (new_stash);
}

char	*get_line(char *stash)
{
	char	*new_line;

	if (!stash)
		return (NULL);
	if (ft_find_newline(stash) >= 0)
		new_line = ft_substr(stash, 0, (ft_find_newline(stash) + 1));
	else
		new_line = ft_substr(stash, 0, ft_strlen(stash));
	return (new_line);
}

// 		 GNL main 
// 	Comment utiliser la fonction :

// 	- remplacer "test.c" pa le nom du fichier
// 	que vous souhaitez lire

// 	- Compiler avec la commande suivante : 
// 	"gcc -D BUFFER_SIZE=N get_next_line.c get_next_line_utils.c"

// 	-> 'n' sera le nombre qui servira a definir la taille de buffer
// 	a utiliser

// 	-> la taille de buffer par defaut est 0.	

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*str;

// 	fd1 = open("test", O_RDWR);
// 	fd2 = open("test2", O_RDWR);
// 	fd3 = open("test3", O_RDWR);
// 	while (42)
// 	{
// 		str = get_next_line(fd1);
// 		printf("main FD1 --> %s", str);
// 		free (str);
// 		str = get_next_line(fd2);
// 		printf("main FD2 --> %s", str);
// 		free (str);
// 		str = get_next_line(fd3);
// 		printf("main FD3 --> %s", str);
// 		free (str);
// 		if (str == NULL)
// 			break ;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
