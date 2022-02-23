/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:21:41 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 21:21:27 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

static void	maxmin_int(long res, int flag)
{
	long	max_int;
	long	min_int;

	max_int = 2147483647;
	min_int = 2147483648;
	if ((res > min_int && flag == -1) || (res > max_int && flag == 1))
	{
		write(1, "max_min_int_error\n", 19);
		exit(0);
	}
}

static int	ft_isspaces(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	unsigned long		i;
	int					sign;
	int					j;

	i = 0;
	j = 0;
	sign = 1;
	while (ft_isspaces(str[j]))
		j++;
	if ((str[j] == '-' || str[j] == '+') && (str[j + 1]))
		if (str[j++] == '-')
			sign = -1;
	while (str[j])
	{
		if (str[j] > '9' || str[j] < '0')
		{
			write(1, "wrong simbol error\n", 20);
			exit (0);
		}
		i = ((i * 10) + (str[j++] - '0'));
	}
	maxmin_int(i, sign);
	return (i * sign);
}
