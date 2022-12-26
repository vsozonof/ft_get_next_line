/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:00 by vsozonof          #+#    #+#             */
/*   Updated: 2022/12/26 16:56:18 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stash;

	line = NULL;
	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	stash = read_and_fill_stash(fd, stash);
	line = get_line(stash);
	stash = extract_from_stash(stash);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_and_fill_stash(int fd, char *stash)
{
	char		tmp[BUFFER_SIZE + 1];
	int			counter;

	counter = 1;
	while (ft_find_newline(stash) == 0 && counter > 0)
	{
		counter = read(fd, tmp, BUFFER_SIZE);
		tmp[counter] = '\0';
		stash = free_and_join_stash(stash, tmp);
		if (!stash || stash[0] == '\0')
			return (NULL);
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

	new_stash = ft_substr(stash, ft_find_newline(stash) + 1,
			(ft_strlen(stash) - ft_find_newline(stash)));
	free(stash);
	return (new_stash);
}

char	*get_line(char *stash)
{
	char	*new_line;

	if (ft_find_newline(stash) == 0 && stash[ft_strlen(stash)] != '\n')
	{	
		new_line = ft_substr(stash, 0, ft_strlen(stash));
		// free(stash);
	}
	else if (ft_find_newline(stash) > 0)
		new_line = ft_substr(stash, 0, ft_find_newline(stash));
	else
		return (NULL);
	return (new_line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test", O_RDWR);
	str = get_next_line(fd);
	printf("--> %s\n\n", str);
	free (str);
	str = get_next_line(fd);
	printf("--> %s\n\n", str);
	free (str);
	str = get_next_line(fd);
	printf("--> %s\n\n", str);
	free (str);
	str = get_next_line(fd);
	printf("--> %s\n\n", str);
	free (str);
	str = get_next_line(fd);
	printf("--> %s\n\n", str);
	free (str);
	str = get_next_line(fd);
	printf("--> %s\n\n", str);
	free (str);
	str = get_next_line(fd);
	printf("--> %s\n\n", str);
	free (str);
	
	// while (42)
	// {
	// 	str = get_next_line(fd);
	// 	printf("--> %s\n", str);
	// 	free (str);
	// 	if (str == NULL)
	// 		break ;
	// }
	close(fd);
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
