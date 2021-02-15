/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:52:58 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/15 14:23:07 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static int	gnl_find_EOF(char **res, char **line)
{
	char	*temp_1;

	temp_1 = *res;
	*line = ft_strdup(*res);
	//free(temp_1);
	return (0);
}

static int	gnl_find_nl(char *buff, char **res, char **line)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = *res;
	temp_2 = ft_strchr(buff, '\n');
	*temp_2 = '\0';
	*line = ft_strdup(*res);
	*res = ft_strdup(temp_2);
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
		//free(temp);
	}
	if (num == 0)
		return (gnl_find_EOF(&res, line));
	else if (num > 0)
		return (gnl_find_nl(buff, &res, line)); 
	else
		return (-1);
}
