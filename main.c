/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:31:52 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/09 14:12:42 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		result;
	int		verif = 0;
	char	*line;

	fd = open("t1_consalto.txt", O_RDONLY);
	if (fd <= 0)
		printf("OPEN ERROR: el archivo no se puede abrir.\n");
	else
	{
		printf("OPEN SUCCESS\n");
		result = get_next_line(fd, &line);
		while (verif == 0)
		{
			if (result == -1)
			{
				printf("READ ERROR: no se puede leer el archivo.\n");
				break ;
			}
			else if (result == 0)
			{
				printf("%s", line);
				break ;
			}
			else if (result == 1)
				printf("%s\n", line);
			result = get_next_line(fd, &line);
		}
	}
	close(fd);
	//system("leaks a.out");
	return (0);
}
