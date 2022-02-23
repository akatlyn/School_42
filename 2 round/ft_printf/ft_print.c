#include "ft_printf.h"

int	ft_print(va_list	vl, t_flag	*flags)
{
	int		len;

	len = 0;
	{
		if (flags->type == 'c')
			len = ft_print_c(flags, va_arg(vl, int));
		if (flags->type == 's')
			len = ft_print_s(flags, va_arg(vl, char *));
		if (flags->type == '%')
			len = ft_print_s(flags, "%");
		if (flags->type == 'd' || flags->type == 'i')
			len = ft_print_digit(flags, va_arg(vl, int));
		if (flags->type == 'u')
			len = ft_print_digit_u(flags, va_arg(vl, unsigned int));
		if (flags->type == 'x')
			len = ft_print_x(flags, va_arg(vl, unsigned int));
		if (flags->type == 'X')
			len = ft_print_xx(flags, va_arg(vl, unsigned int));
		if (flags->type == 'p')
			len = ft_print_p(flags, va_arg(vl, unsigned long));
		return (len);
	}
}
