#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
		ss[i] = s2[l];
		i++;
		l++;
	}
	ss[i] = '\0';
	return (ss);
}
