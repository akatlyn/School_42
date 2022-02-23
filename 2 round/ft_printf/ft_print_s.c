#include "ft_printf.h"

int	ft_print_s(t_flag *flags, char *s)
{
	int		sl;
	int		len;

	len = 0;
	if (!s)
		s = "(null)";
	sl = ft_strlen(s);
	if (flags->precision >= 0)
		if (sl > flags->precision)
			sl = flags->precision;
	if (flags->minus)
		ft_putnstr(s, sl);
	if (flags->width > sl)
	{
		if (flags->null)
			len = ft_print_width(flags->width - sl, 1);
		else
			len = ft_print_width(flags->width - sl, 0);
	}
	if (flags->minus == 0)
		ft_putnstr(s, sl);
	return (sl + len);
}
