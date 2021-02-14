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

	if (*res)
	{
		free(*line);
		free(*res);
		if ((temp = ft_strchr(*res , '\n')))
		{
			*temp = '\0';
			temp++;
			*line = ft_strdup(*res);
			*res = ft_strdup(temp);
			return (1);
		}
		else
			*line = ft_strdup(*res);
	}
	else
		*line = gnl_strnew(1);
	return (0);
}

static void	gnl_buff_nl(char *buff, char **res, char **line)
{
	char	*temp;

	temp = ft_strchr(buff, '\n');
	*temp = '\0';
	temp++;
	*line = ft_strjoin(*line, buff);
	*res = ft_strdup(temp);
}

int			get_next_line(int fd, char **line)
{
	static char	*res;
	char		buff[BUFFER_SIZE + 1];
	int			verif;
	int			num;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if ((num = gnl_look_in_res(&res, line)) == 1)
		return (1);
	while ((num = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num] = '\0';
		if ((verif = gnl_look_for_nl(buff)) == 1)
		{
			gnl_buff_nl(buff, &res, line);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	if (num == 0)
		return (0);
	return (-1);
}
