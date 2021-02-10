/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:15:20 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/10 09:48:40 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd;
    int r;
    char *line = 0;
    int i = 0;

    fd = 0;
    fd = open("t1_consalto.txt", O_RDONLY);
    r = 1;
    while (r == 1)
    {
        r = get_next_line(fd, &line);
        //printf("%i", r);
        printf("\n%s\n", line);
        if (line)
            free(line);
        i++;
    }
    close(fd);
    printf ("Termina, valor de r final: %i\n", r);
    system("leaks a.out");
    return (0);
}
