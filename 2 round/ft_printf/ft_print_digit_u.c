#include "ft_printf.h"

static int	ft_precision_minus(char *su, int su_l, t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->width > su_l && flags->minus == 0)
	{
		if (!flags->null)
			len = ft_print_width(flags->width - su_l, 0);
		else if (flags->null)
			len = ft_print_width(flags->width - su_l, 1);
	}
	ft_putnstr(su, su_l);
	if (flags->width > su_l && flags->minus == 1)
		len = ft_print_width(flags->width - su_l, 0);
	return (len + su_l);
}

static int	ft_precision_plus(char *su, int su_l, t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > su_l)
			len = ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > su_l)
			len = ft_print_width(flags->width - su_l, 0);
	}
	if (flags->precision > su_l)
		len += ft_print_width(flags->precision - su_l, 1);
	ft_putnstr(su, su_l);
	if (flags->width > flags->precision && flags->minus == 1)
	{
		if (flags->precision > su_l)
			len += ft_print_width(flags->width - flags->precision, 0);
		else if (flags->width > su_l)
			len += ft_print_width(flags->width - su_l, 0);
	}
	return (len + su_l);
}

int	ft_print_digit_u(t_flag *flags, unsigned int u)
{
	char	*su;
	int		su_l;
	int		len;

	len = 0;
	if (flags->precision == 0 && u == 0)
	{
		len = ft_print_width(flags->width, 0);
		return (len);
	}
	su = ft_itoa_d(u);
	su_l = ft_strlen(su);
	if (flags->precision == -1)
		len = ft_precision_minus(su, su_l, flags);
	else if (flags->precision >= 0)
		len = ft_precision_plus(su, su_l, flags);
	free(su);
	return (len);
}
