#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			l;
	size_t			s;

	i = 0;
	l = ft_strlen(dst);
	s = ft_strlen(dst) + ft_strlen(src);
	 if (l > size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && size > 0 && l < size - 1)
		dst[l++] = src[i++];
	dst[l] = '\0';
	return (s);
}
