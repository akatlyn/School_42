#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbuf;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if ((size_t) start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sbuf = (char *)malloc(sizeof(char) * len + 1);
	if (sbuf == 0)
		return (0);
	while (len > 0)
	{
		sbuf[i++] = s[start++];
		len--;
	}
	sbuf[i] = '\0';
	return (sbuf);
}
