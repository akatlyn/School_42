#include "ft_printf.h"

static int	ft_len(unsigned long x)
{
	int		len;

	len = 0;
	if (x == 0)
		return (1);
	while (x != 0)
		x = x / 16, len++;
	return (len);
}

static char	*ft_itoa_x(unsigned int x)
{
	char	*xs;
	int		i;

	i = ft_len(x);
	xs = malloc(i + 1);
	if (!xs)
		return (NULL);
	xs[i--] = '\0';
	if (x == 0)
	{
		xs[0] = '0';
	}
	while (i >= 0)
	{
		if (x % 16 < 10)
			xs[i--] = (x % 16) + 48;
		else
			xs[i--] = (x % 16) + 55;
		x /= 16;
	}
	return (xs);
}

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

int	ft_print_xx(t_flag *flags, unsigned int x)
{
	unsigned long	cst_x;
	char			*xs;
	int				xs_l;
	int				len;

	len = 0;
	if (flags->precision == 0 && x == 0)
	{
		len = ft_print_width(flags->width, 0);
		return (len);
	}
	cst_x = (unsigned long)x;
	xs = ft_itoa_x(cst_x);
	xs_l = ft_strlen(xs);
	if (flags->precision == -1)
		len = ft_precision_minus(xs, xs_l, flags);
	else if (flags->precision >= 0)
		len = ft_precision_plus(xs, xs_l, flags);
	free(xs);
	return (len);
}
