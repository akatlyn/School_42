#include "ft_printf.h"

static	int	ft_precision_minus(char *dis, int di_l, t_flag *flags, int len)
{
	di_l++;
	if ((flags->width > di_l) && flags->minus == 0)
	{
		if ((flags->width - di_l) > 0 && flags->null == 0)
		{
			len += ft_print_width(flags->width - di_l, 0);
			ft_putchar('-');
		}
		else if ((flags->width - di_l) > 0)
		{
			ft_putchar('-');
			len += ft_print_width(flags->width - di_l, 1);
		}
		ft_putnstr(dis, di_l - 1);
	}
	else
	{
		ft_putchar('-');
		ft_putnstr(dis, di_l - 1);
		if (flags->minus == 1 && (flags->width - di_l) > 0)
			len += ft_print_width(flags->width - di_l, 0);
	}
	return (len + 1);
}

static	int	ft_precision_plus(char *dis, int di_l, t_flag *flags, int len)
{
	if (flags->width > flags->precision && !flags->minus)
	{
		if (flags->precision > di_l)
			len += ft_print_width(flags->width - flags->precision - 1, 0);
		else if (flags->width - di_l - 1 > 0)
			len += ft_print_width(flags->width - di_l - 1, 0);
	}
	ft_putchar('-');
	if (flags->precision > di_l)
		len += ft_print_width(flags->precision - di_l, 1);
	ft_putnstr(dis, di_l);
	if (flags->width > flags->precision && flags->minus == 1)
	{
		if (flags->precision > di_l)
			len += ft_print_width(flags->width - flags->precision - 1, 0);
		else if (flags->width - di_l - 1 > 0)
			len += ft_print_width(flags->width - di_l - 1, 0);
	}
	return (len + 1);
}

int	ft_digit_minus(t_flag *flags, int di)
{
	unsigned int	cst;
	int				di_l;
	int				len;
	char			*dis;

	len = 0;
	cst = (unsigned int)di * -1;
	dis = ft_itoa_d(cst);
	di_l = ft_strlen(dis);
	if (flags->precision == -1)
		len = ft_precision_minus(dis, di_l, flags, len);
	else if (flags->precision >= 0)
		len = ft_precision_plus(dis, di_l, flags, len);
	free(dis);
	return (len + di_l);
}
