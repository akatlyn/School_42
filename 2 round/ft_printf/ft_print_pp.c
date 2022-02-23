#include "ft_printf.h"

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static int	ft_precision_p(char *s, t_flag *flags, unsigned long p, int len)
{
	if ((flags->precision > len && flags->precision < flags->width)
		&& flags->minus == 0)
	{
		len += ft_print_width(flags->width - flags->precision - 2, 0);
		ft_putnstr("0x", 2);
		len += ft_print_width(flags->precision - len + 3, 1);
		len += 2;
		ft_putstr(s);
	}
	if (flags->precision > len)
	{
		ft_putnstr("0x", 2);
		len += 2;
		len += ft_print_width(flags->precision - len + 2, 1);
		if (p)
			ft_putstr(s);
		if (flags->minus && flags->width - len > 0)
			len += ft_print_width(flags->width - len, 0);
	}
	return (len);
}

static int	ft_width_p(char *s, t_flag *flags, int len)
{
	if (flags->width > len)
	{
		if ((flags->width - len > 2) && flags->minus == 0)
		{
			len += ft_print_width(flags->width - len - 2, 0);
			ft_putnstr("0x", 2);
			len += 2;
			ft_putstr(s);
		}
		else
		{
			ft_putnstr("0x", 2);
			len += 2;
			ft_putstr(s);
			if (flags->width - len > 0)
				len += ft_print_width(flags->width - len, 0);
		}
	}
	else
	{
		ft_putnstr("0x", 2);
		len += 2;
		ft_putstr(s);
	}
	return (len);
}

int	ft_print_pp(char *s, t_flag *flags, unsigned long p, int len)
{
	if (flags->precision > len)
		len = ft_precision_p(s, flags, p, len);
	else if (flags->width == 0)
	{
		ft_putnstr("0x", 2);
		len += 2;
		if (flags->precision)
			ft_putstr(s);
	}
	else if (flags->width)
		len = ft_width_p(s, flags, len);
	return (len);
}
