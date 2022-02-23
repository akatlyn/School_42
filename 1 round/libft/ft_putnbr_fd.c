#include	"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	mass[11];
	long	f;
	int		i;

	i = 0;
	f = n;
	if (f == 0)
		ft_putchar_fd('0', fd);
	if (f < 0)
	{
		ft_putchar_fd('-', fd);
		f *= -1;
	}
	while (f > 0)
	{
		mass[i] = f % 10 + 48;
		f = f / 10;
		i++;
	}
	mass[i] = '\0';
	i--;
	while (i >= 0)
		write(fd, &(mass[i--]), 1);
}
