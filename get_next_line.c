/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:00 by vsozonof          #+#    #+#             */
/*   Updated: 2022/12/05 03:37:48 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	counter;
	char		*line;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	counter = read(fd, line, BUFFER_SIZE);
	line[counter] = '\0';
	return (line);

}

int main()
{
	int fd;
	char *str;
	int i = 0;

	
	fd = open("test.c", O_RDWR);
	
	while (i++ < 11)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
	
}