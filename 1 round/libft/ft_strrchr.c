#include	"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	a;

	a = (unsigned char) c;
	i = ft_strlen(str);
	if (str[i] == a)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == a)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
