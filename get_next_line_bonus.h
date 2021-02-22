/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 08:42:11 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/22 09:44:25 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef M_SIZE
#  define M_SIZE 65535
# endif

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(char const *s, int c);

char	*ft_strdup(char const *s1);

#endif
