#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ss;

	i = 0;
	if (s == 0)
		return (0);
	ss = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (ss == 0)
		return (0);
	while (s[i] != '\0')
	{
		ss[i] = f(i, s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
