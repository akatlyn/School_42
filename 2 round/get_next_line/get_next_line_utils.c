#include	"get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*dstr;
	int		i;

	i = 0;
	dstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dstr == 0)
		return (0);
	while (str[i] != '\0')
	{
		dstr[i] = str[i];
		i++;
	}
	dstr[i] = '\0';
	return (dstr);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char) c)
		return ((char *)str + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	ss = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (ss == 0)
		return (0);
	while (s1[i] != '\0')
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2[l] != '\0')
	{
		ss[i++] = s2[l++];
	}
	ss[i] = '\0';
	free(s1);
	return (ss);
}

char	*ft_strcpy(char	*s1, char	*s2)
{
	while (s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1);
}
