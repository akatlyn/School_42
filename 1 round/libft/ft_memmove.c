#include	"libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if (str1 == 0 && str2 == 0)
		return (str1);
	dest = (unsigned char *) str1;
	src = (unsigned char *) str2;
	i = 0;
	if (src < dest)
	{
		while (i < n)
		{
			dest[n - 1 - i] = src[n - 1 - i];
			i++;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (str1);
}
