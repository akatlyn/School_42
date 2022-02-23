#include "ft_printf.h"

t_flag	ft_init(void)
{
	t_flag		flag;

	flag.type = '0';
	flag.minus = 0;
	flag.width = 0;
	flag.precision = -1;
	flag.minus = 0;
	flag.null = 0;
	return (flag);
}
