#include "ft_printf.h"

static int	ft_precision_minus(char *dis, int di_l, t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->width > di_l && flags->minus == 0)
	{
		if (!flags->null)
			len = ft_print_width(flags->width - di_l, 0);
		else if (flags->null)
			len = ft_print_width(flags->width - di_l, 1);
	}
	ft_putnstr(dis, di_l);
	if (flags->width > di_l && flags->minus == 1)
		len = ft_print_width(flags->width - di_l, 0);
	return (len + di_l);
}

static int	ft_precision_plus(char *dis, int di_l, t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > di_l)
			len = ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > di_l)
			len = ft_print_width(flags->width - di_l, 0);
	}
	if (flags->precision > di_l)
		len += ft_print_width(flags->precision - di_l, 1);
	ft_putnstr(dis, di_l);
	if (flags->width > flags->precision && flags->minus == 1)
	{
		if (flags->precision > di_l)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > di_l)
			len += ft_print_width(flags->width - di_l, 0);
	}
	return (len + di_l);
}

int	ft_digit_plus(t_flag *flags, int di)
{
	int		len;
	int		di_l;
	char	*dis;

	len = 0;
	if (flags->precision == 0 && di == 0)
	{
		len = ft_print_width(flags->width, 0);
		return (len);
	}
	dis = ft_itoa_d(di);
	di_l = ft_strlen(dis);
	if (flags->precision == -1)
		len = ft_precision_minus(dis, di_l, flags);
	else if (flags->precision >= 0)
		len = ft_precision_plus(dis, di_l, flags);
	free(dis);
	return (len);
}
