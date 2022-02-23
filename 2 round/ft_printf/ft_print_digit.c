#include "ft_printf.h"

int	ft_print_digit(t_flag *flags, int di)
{
	int		len;

	len = 0;
	if (di >= 0)
		len = ft_digit_plus(flags, di);
	else
		len = ft_digit_minus(flags, di);
	return (len);
}
