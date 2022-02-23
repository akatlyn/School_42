/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:13:42 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/07 14:41:13 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *ptr)
{
	unsigned int	res;
	unsigned int	last_res;
	int				sign;

	res = 0;
	sign = 1;
	while ((9 <= *ptr && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '-')
		sign = -1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (ft_isdigit(*ptr))
	{
		last_res = res;
		res = res * 10 + *ptr - '0';
		if (last_res > res)
			return (0);
		ptr++;
		if (*ptr && (*ptr < 48 || *ptr > 57))
			return (0);
	}
	return (res * sign);
}
