/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:52:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/16 09:42:22 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_bzero(char *s, size_t n)
{
	unsigned char	*p;
	size_t			a;

	p = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		p[a] = '\0';
		a++;
	}
}

int		delmem(char **p)
{
	if (p)
	{
		if (*p)
		{
			ft_bzero(*p, ft_strlen(*p));
			free(*p);
			*p = NULL;
			return (1);
		}
	}
	return (0);
}

static int	gnl_find_EOF(char **res, char **line)
{
	char	*temp_1;
	char	*temp_2;

	if ((temp_1 = ft_strchr(*res, '\n')))
	{
		temp_2 = *res;
		*temp_1 = '\0';
		temp_1++;
		*line = ft_strdup(*res);
		*res = ft_strdup(temp_1);
		return (1);
	}
	*line = ft_strdup(*res);
	delmem(res);
	return (0);
}

static int	gnl_find_nl(char **res, char **line)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = *res;
	temp_2 = ft_strchr(*res, '\n');
	*temp_2 = '\0';
	temp_2++;
	*line = ft_strdup(*res);	
	*res = ft_strdup(temp_2);
	delmem(&temp_1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*res;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			num;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!res)
		res = ft_strdup("");
	while (!(ft_strchr(res , '\n')) && (num = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num] = '\0';
		temp = res;
		res = ft_strjoin(res, buff);
		free(temp);
	}
	if (num == 0)
		return (gnl_find_EOF(&res, line));
	else if (num > 0)
		return (gnl_find_nl(&res, line)); 
	free(res);
	return (-1);
}
