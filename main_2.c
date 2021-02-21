/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:15:20 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/16 12:32:47 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd_1;
	int fd_2;
	int r_1;
	int r_2;
	char *line = 0;
	int i = 0;

	fd_1 = open("t1_consalto.txt", O_RDONLY);
	fd_2 = open("texto.txt", O_RDONLY);
	r_1 = 1;
	r_2 = 1;
	while (r_1 == 1 || r_2 == 1)
	{
		if (r_1 == 1){
			r_1 = get_next_line(fd_1,  &line);
			if (line)
				free(line);
			printf("%s\n", line);
		}
		if (r_2 == 1){
			r_2 = get_next_line(fd_2, &line);
			if (line)
				free(line);
			printf("%s\n", line);
		}
		i++;
	}
	printf("\n\nFINAL\n\n");
	close(fd_1);
	close(fd_2);
	system("leaks a.out");
	return (0);
}
