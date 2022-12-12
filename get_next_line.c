/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:00 by vsozonof          #+#    #+#             */
/*   Updated: 2022/12/12 15:38:11 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	counter;
	static char	*line;
	static char	*stash = NULL;

	if (BUFFER_SIZE == 0)
		return (NULL);
	line = read_and_fill_stash(fd, stash);
	return (line);
}

char	*read_and_fill_stash(int fd, char *stash)
{
	static char		tmp[BUFFER_SIZE + 1];
	static int		counter;

	while (ft_find_newline(tmp) < 0)
	{
		counter = read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE + 1] = '\0';
		stash = free_and_join_stash(stash, tmp);
	}
	return (stash);
}

char	*free_and_join_stash(char *stash, char *tmp)
{
	static char	*new_stash;

	new_stash = ft_strjoin(stash, tmp);
	free (stash);
	return (new_stash);
}

char	*extract_from_stash(char *stash, char *tmp)
{
	
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test", O_RDWR);
	while (42)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("--> %s\n", str);
		free (str);
	}
	return (0);
}



/* 		
		/!\ GNL main /!\
	Comment utiliser la fonction :

	- remplacer "test.c" pa le nom du fichier
	que vous souhaitez lire

	- Compiler avec la commande suivante : 
	"gcc -D BUFFER_SIZE=N get_next_line.c get_next_line_utils.c"

	-> 'n' sera le nombre qui servira a definir la taille de buffer
	a utiliser

	-> la taille de buffer par defaut est 0.	
*/

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("test.c", O_RDWR);
// 	while (42)
// 	{
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;
// 		printf("%s\n", str);
// 		free (str);
// 	}
// 	return (0);
// }
