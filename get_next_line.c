/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:52:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/10 12:43:04 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*gnl_strnew(int n)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	return (ptr);
}

static int	gnl_look_in_res(char **res, char *temp, char **line)
{
	if (*res == NULL)
	{
		*res = gnl_strnew(1);
		free(*res);
	}
	if ((temp = ft_strchr(*res, '\n')))
	{
		*line = ft_memccpy(*res, '\n', BUFFER_SIZE);
		free(*res);
		*res = ft_strdup(temp);
		free(temp);
		return (1);
	}
	*line = ft_strdup(*res);
	return (0);
}

static int	gnl_look_for_nl(const char *s1, int c)
{
	int	count;

	count = 0;
	while (s1[count])
	{
		if (s1[count] == (unsigned char)c)
			return (1);
		count++;
	}
	return (0);
}

/*static void	gnl_buff_nl(char *buff, char **res, char *temp, char **line)
{
	temp = ft_memccpy(buff, '\n', BUFFER_SIZE);
	*line = ft_strjoin(*line, temp);
	free(temp);
	temp = NULL;
	*res = ft_strchr(buff, '\n');
}*/

int			get_next_line(int fd, char **line)
{
	static char	*res;
	char		*temp;
	char		buff[BUFFER_SIZE + 1];
	int			verif;
	int			num;

	if (!(fd >= 0 && fd < 123) || BUFFER_SIZE <= 0 || !line)
		return (-1);
	temp = NULL;
	if ((num = gnl_look_in_res(&res, temp, line)) == 1)
		return (1);
	while ((num = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num] = '\0';
		if ((verif = gnl_look_for_nl(buff, '\n')) == 1)
		{
			//gnl_buff_nl(buff, &res, temp, line);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	return (0);
}
