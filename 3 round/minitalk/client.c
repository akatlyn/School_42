#include "minitalk.h"

void	ft_send_char(int pid, char c)
{
	int		count;
	int		bit;

	count = 0;
	bit = 0;
	while (count < 8)
	{
		bit = (c >> count) & 1;
		if (bit == 1)
			bit = kill(pid, SIGUSR1);
		else
			bit = kill(pid, SIGUSR2);
		if (bit == -1)
		{
			ft_putstr("*SIGNAL ERROR*\n");
			exit(1);
		}
		count++;
		usleep(200);
	}
}

void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
	ft_send_char(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 0)
		{
			ft_putstr("*INVALID PROCESS ID*\n");
			exit(1);
		}
		ft_send_str(pid, argv[2]);
	}
	else
		ft_putstr("*WRONG NUMBER ARGUMENTS*\n");
}
