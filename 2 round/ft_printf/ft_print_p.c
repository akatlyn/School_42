#include "ft_printf.h"

static	int	ft_len_p(unsigned long x)
{
	int		len;

	len = 0;
	if (x == 0)
		return (1);
	while (x != 0)
		x = x / 16, len++;
	return (len);
}

static char	*ft_itoa_p(unsigned long x)
{
	char	*xs;
	int		i;

	i = ft_len_p(x);
	xs = malloc(i + 1);
	if (!xs)
		return (NULL);
	xs[i--] = '\0';
	if (x == 0)
		xs[0] = '0';
	while (i >= 0)
	{
		if (x % 16 < 10)
			xs[i--] = (x % 16) + 48;
		else
			xs[i--] = (x % 16) + 87;
		x /= 16;
	}
	return (xs);
}

static	char	*ft_strdup(const char *str)
{
	char	*dstr;
	int		i;

	i = 0;
	dstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dstr == 0)
		return (0);
	while (str[i] != '\0')
	{
		dstr[i] = str[i];
		i++;
	}
	dstr[i] = '\0';
	return (dstr);
}

int	ft_print_p(t_flag *flags, unsigned long p)
{
	char			*s;
	int				p_l;
	int				len;

	len = 1;
	p_l = 0;
	if (p == 0 && flags->precision == -1)
		s = ft_strdup("0");
	else
	{
		if (p)
			p_l = ft_len_p(p);
		else
			p_l = 0;
		len = p_l;
		s = ft_itoa_p(p);
	}
	len = ft_print_pp(s, flags, p, len);
	free(s);
	return (len);
}
