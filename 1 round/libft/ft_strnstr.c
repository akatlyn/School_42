#include	"libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (needle[0] == '\0')
		return ((char *) stack);
	while (stack[i] != '\0' && i < len)
	{
		if (stack[i] == needle[0])
		{
			while (stack[i + l] == needle[l] && (i + l) < len)
			{
				if (needle[l + 1] == '\0')
					return ((char *)stack + i);
				l++;
			}
		}
		i++;
	}
	return (0);
}
