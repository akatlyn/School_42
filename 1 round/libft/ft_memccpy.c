#include	"libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *) dest;
	s2 = (unsigned char *) src;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == (unsigned char) c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
