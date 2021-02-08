/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:52:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/08 14:10:58 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_get_nl(char *buff, char *res, char *temp, char **line)
{
	temp = ft_memccpy(buff, '\n', BUFFER_SIZE);
	*line = ft_strjoin(*line, temp);
	free(temp);
	free(res);
	temp = NULL;
	res = ft_strchr(buff, '\n');
}

int		look_in_res(char *res, char *temp, char **line)
{
	if (res != NULL)
		free(*line);
	res = (res == NULL) ? ft_strnew(1) : res;
	if ((temp = ft_strchr(res, '\n')))
	{
		*line = ft_memccpy(res, '\n', BUFFER_SIZE);
		free(res);
		res = temp;
		return (1);
	}
	*line = ft_strdup(res);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*res;
	char		*temp;
	char		buff[BUFFER_SIZE];
	int			verif;
	int			num;

	if (!(fd >= 0 && fd < 123) || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if ((num = look_in_res(res, temp, &*line)) == 1)
		return (1);
	while ((num = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num] = '\0';
		if ((verif = look_for_nl(buff, '\n')) == 1)
		{
			ft_get_nl(buff, res, temp, &*line);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	return (0);
}
