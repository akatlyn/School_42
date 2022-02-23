#include	"libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	a = (unsigned char *)str1;
	b = (unsigned char *)str2;
	i = 0;
	while ((a[i] != '\0' || b[i] != '\0') && n--)
	{
		if (a[i] != b[i])
			return ((int) a[i] - (int) b[i]);
		i++;
	}
	return (0);
}
