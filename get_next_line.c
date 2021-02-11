/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:52:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/11 09:41:16 by pgomez-a         ###   ########.fr       */
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

static int	gnl_look_for_nl(const char *s1)
{
	int	count;

	count = 0;
	while (s1[count])
	{
		if (s1[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

static int	gnl_look_in_res(char **res, char **line)
{
	char	*temp;
	int		verif;

	if (*res == NULL)
	{
		*res = gnl_strnew(1);
		free(*res);
	}
	if ((verif = gnl_look_for_nl(*res)) == 1)
	{
		temp = ft_strchr(*res, '\n');
		*line = ft_memccpy(*res, '\n', BUFFER_SIZE);
		free(*res);
		*res = ft_strdup(temp);
		free(temp);
		temp = NULL;
		return (1);
	}
	*line = ft_strdup(*res);
	return (0);
}

static void	gnl_buff_nl(char *buff, int prov, char **res, char **line)
{
	char	*temp;

	temp = ft_memccpy(buff, '\n', BUFFER_SIZE);
	*line = ft_strjoin(*line, temp);
	free(temp);
	temp = NULL;
	if (prov == 1)
		free(*res);
	*res = ft_strchr(buff, '\n');
}

int			get_next_line(int fd, char **line)
{
	static char	*res;
	char		buff[BUFFER_SIZE + 1];
	int			verif;
	int			num;
	int			prov;

	prov = 1;
	if (res == NULL)
		prov = 0;
	if (!(fd >= 0 && fd < 123) || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if ((num = gnl_look_in_res(&res, line)) == 1)
		return (1);
	while ((num = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num] = '\0';
		if ((verif = gnl_look_for_nl(buff)) == 1)
		{
			gnl_buff_nl(buff, prov, &res, line);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	return (0);
}
