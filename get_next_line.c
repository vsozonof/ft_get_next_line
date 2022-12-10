/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:00 by vsozonof          #+#    #+#             */
/*   Updated: 2022/12/10 18:03:34 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	counter;
	char		*line;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	counter = read(fd, line, BUFFER_SIZE);
	if (counter == 0)
		return (NULL);
	line[counter] = '\0';
	return (line);

}



/* 		/!\ My GNL main /!\ 
	How to use the function :
	
	- replace "test.c" with the name of the 
	file you are trying to read
	
	- Compile with the following command :
	"gcc -D BUFFER_SIZE=N get_next_line.c get_next_line_utils.c"
	
	-> you must replace N with a number of your choice, it will
	be used to define the size of the buffer.
	-> BUFFER_SIZE will be set to 0 by default */

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.c", O_RDWR);
	while (42)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s\n", str);
		free (str);
	}
	return (0);
}
