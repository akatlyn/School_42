#include	"ft_printf.h"

int	ft_print_width(int	width, int null)
{
	int		len;

	len = 0;
	while (width > 0)
	{
		if (!null)
			ft_putchar(' ');
		else
			ft_putchar('0');
		width--;
		len++;
	}
	return (len);
}

int	ft_print_c(t_flag *flags, char c)
{
	int		len;

	len = 0;
	if (flags->minus == 1)
		ft_putchar(c);
	if (flags->null == 1)
		len = ft_print_width(flags->width - 1, 1);
	if (flags->null == 0)
		len = ft_print_width(flags->width - 1, 0);
	if (flags->minus == 0)
		ft_putchar(c);
	return (len + 1);
}
