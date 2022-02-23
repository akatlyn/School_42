/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:42:00 by akatlyn           #+#    #+#             */
/*   Updated: 2021/07/29 23:45:29 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	mass[11];
	long	f;
	int		i;

	i = 0;
	f = n;
	if (f == 0)
		ft_putchar('0');
	if (f < 0)
	{
		ft_putchar('-');
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
		write(1, &(mass[i--]), 1);
}

void	ft_putstr(char *s)
{
	if (s == 0)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}
