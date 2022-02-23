#include	"libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;

	i = 0;
	s1 = (unsigned char *) arr1;
	s2 = (unsigned char *) arr2;
	while (n != 0)
	{
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
		i++;
		n--;
	}
	return (0);
}
