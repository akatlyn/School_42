#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)b;
	i = 0;
	while (i < len)
		res[i++] = (unsigned char)c;
	return (res);
}
