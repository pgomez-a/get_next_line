/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 08:41:05 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/08 14:32:59 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		count_s1;
	int		count_s2;

	if (!s1 || !s2)
		return (NULL);
	count_s1 = ft_strlen(s1);
	count_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc((count_s1 + count_s2 + 1) * sizeof(char))))
		return (0);
	str[count_s1 + count_s2] = '\0';
	while (count_s2 > 0)
	{
		str[count_s1 + count_s2 - 1] = s2[count_s2 - 1];
		count_s2--;
	}
	while (count_s1 > 0)
	{
		str[count_s1 - 1] = s1[count_s1 - 1];
		count_s1--;
	}
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		count;
	int		t;
	char	*res;

	count = 0;
	t = 0;
	if (!(res = (char *)malloc(ft_strlen(s) * sizeof(char))))
		return (NULL);
	while (s[count] && (s[count] != (unsigned char)c))
		count++;
	if (s[count] == (unsigned char)c)
	{
		count++;
		while (s[count])
		{
			res[t] = s[count];
			count++;
			t++;
		}
		res[t] = '\0';
		return (res);
	}
	free(res);
	return (NULL);
}

char	*ft_memccpy(char *src, int c, int n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(n * sizeof(char))))
		return (NULL);
	while (i < n && src[i] != c)
	{
		str[i] = src[i];
		i++;
	}
	if (str[i] == c)
	{
		str[i] = '\0';
		return (str);
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		count;
	char	*str;

	count = 0;
	while (s1[count])
		count++;
	if (!(str = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	count = 0;
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
