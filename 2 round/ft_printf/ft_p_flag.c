#include	"ft_printf.h"

int	ft_min(const char *s1, t_flag	*flags, int *i)
{
	while (s1[*i] == '-' || s1[*i] == '0')
	{
		if (s1[*i] == '-')
			flags->minus = 1;
		else if (s1[*i] == '0')
			flags->null = 1;
		(*i)++;
	}
	if (flags->minus == 1)
		flags->null = 0;
	return (*i);
}

int	ft_width(const char	*s1, t_flag	*flags, va_list vl, int *i)
{
	if (s1[*i] == '*')
	{
		flags->width = va_arg(vl, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
			flags->null = 0;
		}
		(*i)++;
	}
	while (ft_isdigit(s1[*i]))
		flags->width = (s1[(*i)++] - '0') + (flags->width * 10);
	return (*i);
}

int	ft_prec_sec(const char *s1, t_flag *flags, int *i)
{
	char	a;
	int		b;

	a = '0';
	b = 0;
	if (s1[*i] == '-')
	{
		flags->minus = 1;
		flags->precision = 0;
		a = '-';
		(*i)++;
	}
	while (ft_isdigit(s1[*i]))
		b = (s1[(*i)++] - '0') + (b * 10);
	if (a == '-')
		flags->width = b;
	else if (a == '0')
		flags->precision = b;
	return (*i);
}

int	ft_precision(const char	*s1, t_flag	*flags, va_list vl, int *i)
{
	int		l;

	l = 0;
	if (s1[*i] == '.')
	{
		(*i)++;
		if (s1[*i] == '*')
		{
			l = va_arg(vl, int);
			if (l >= 0)
				flags->precision = l;
			(*i)++;
		}
		else
			*i = ft_prec_sec(s1, flags, i);
	}
	return (*i);
}

int	ft_p_flag(const char *s1, va_list vl, int	*i, t_flag *flags)
{
	*i = ft_min(s1, flags, i);
	*i = ft_width(s1, flags, vl, i);
	*i = ft_precision(s1, flags, vl, i);
	if (s1[*i] == 'c' || s1[*i] == 's' || s1[*i] == 'd'
		|| s1[*i] == 'i' || s1[*i] == 'u'
		|| s1[*i] == 'p' || s1[*i] == 'x' || s1[*i] == 'X' || s1[*i] == '%')
		flags->type = s1[(*i)++];
	return (*i);
}
