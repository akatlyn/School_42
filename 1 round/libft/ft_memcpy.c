#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*str;

	if (str1 == 0 && str2 == 0)
		return (str1);
	i = 0;
	dest = (unsigned char *)str1;
	str = (unsigned char *)str2;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (str1);
}
