/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:52:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/16 11:01:45 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_find_eof(int fd, char **res, char **line)
{
	char	*temp_1;
	char	*temp_2;

	if ((temp_2 = ft_strchr(*res[fd], '\n')))
	{
		temp_1 = *res[fd];
		*temp_2 = '\0';
		temp_2++;
		*line = ft_strdup(*res[fd]);
		*res[fd] = ft_strdup(temp_2);
		free(temp_1);
		return (1);
	}
	*line = ft_strdup(*res[fd]);
	free(*res[fd]);
	*res[fd] = NULL;
	return (0);
}

static int	gnl_find_nl(int fd, char **res, char **line)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = *res[fd];
	temp_2 = ft_strchr(*res[fd], '\n');
	*temp_2 = '\0';
	temp_2++;
	*line = ft_strdup(*res[fd]);
	*res[fd] = ft_strdup(temp_2);
	free(temp_1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*res[M_SIZE];
	char		*temp;
	char		buff[BUFFER_SIZE + 1];
	int			num;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!res[fd])
		res[fd] = ft_strdup("");
	while (!(ft_strchr(res[fd], '\n')) && (num = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num] = '\0';
		temp = res[fd];
		res[fd] = ft_strjoin(res[fd], buff);
		free(temp);
	}
	if (num == 0)
		return (gnl_find_eof(fd, &res, line));
	else if (num > 0)
		return (gnl_find_nl(fd, &res, line));
	free(res[fd]);
	return (-1);
}
