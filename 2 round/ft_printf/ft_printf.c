#include "ft_printf.h"

int	ft_parser(va_list vl, const char *s1)
{
	t_flag		flags;
	int			i;
	int			len;

	len = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '\0')
			break ;
		if (s1[i] == '%' && s1[i + 1])
		{
			i++;
			flags = ft_init();
			i = ft_p_flag(s1, vl, &i, &flags);
			len += ft_print(vl, &flags);
		}
		else
		{
			ft_putchar(s1[i++]);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *s1, ...)
{
	va_list		vl;
	int			len;

	len = 0;
	va_start(vl, s1);
	len = ft_parser(vl, s1);
	va_end(vl);
	return (len);
}
