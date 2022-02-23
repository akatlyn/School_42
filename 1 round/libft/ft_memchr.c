#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ar;
	size_t			i;

	ar = (unsigned char *) arr;
	i = 0;
	while (n != 0)
	{
		if (ar[i] == (unsigned char) c)
			return (ar + i);
		i++;
		n--;
	}
	return (0);
}
