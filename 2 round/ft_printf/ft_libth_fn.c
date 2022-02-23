#include	"ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnstr(char *s, int len)
{
	while (len > 0)
	{
		write(1, s++, 1);
		len--;
	}
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_itoa_d(unsigned int di)
{
	char				*s;
	unsigned int		i;
	unsigned int		rm;

	i = 0;
	rm = di;
	if (di == 0)
		i = 1;
	while (rm)
		rm /= 10, i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (di == 0)
		s[0] = '0';
	while (i)
	{
		s[i--] = (di % 10) + '0';
		di /= 10;
	}
	s[i] = di + '0';
	return (s);
}
