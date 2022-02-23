#include	"libft.h"

int	ft_isprint(int c)
{
	if (0x20 <= c && c <= 0x7E)
		return (1);
	return (0);
}
