/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:37:46 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/18 17:40:50 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("GNL [line %d]: %s", count, line);
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
