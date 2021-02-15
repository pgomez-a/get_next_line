#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	count_s1;
	int	count_s2;

	if (!s1 || !s2)
		return (NULL);
	count_s1 = ft_strlen(s1);
	count_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (count_s1 + count_s2 + 1))))
		return (NULL);
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
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] && (s[count] != (unsigned char)c))
		count++;
	if (s[count] == (unsigned char)c)
		return ((char *)s + count);
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int	count;
	char	*str;

	count = 0;
	while (s1[count])
		count++;
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
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
