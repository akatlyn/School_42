#include	"libft.h"

static int	ft_isspaces(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi (const char *str)
{
	unsigned long		l;
	unsigned long		i;
	int					sign;

	i = 0;
	l = 9223372036854775807;
	sign = 1;
	while (ft_isspaces(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) != 0)
	{
		i = ((i * 10) + (*str - '0'));
		if (i > l + 1 && sign == -1)
			return (0);
		if (i > l && sign == 1)
			return (-1);
		str++;
	}
	return (i * sign);
}
