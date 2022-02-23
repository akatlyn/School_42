/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_for_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:08:15 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 19:11:42 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swaps(t_pull *stacks)
{
	int		x1;
	int		x2;
	int		x3;

	x1 = stacks->a->cont;
	x2 = stacks->a->next->cont;
	x3 = stacks->a->next->next->cont;
	if (x1 < x3 && x2 > x3)
	{
		sa(stacks);
		ra(stacks);
	}
	if (x1 > x2 && x1 < x3)
		sa(stacks);
	if (x1 < x2 && x1 > x3)
		rra(stacks);
	if (x1 > x3 && x2 < x3)
		ra(stacks);
	if (x1 > x2 && x2 > x3)
	{
		sa(stacks);
		rra(stacks);
	}
}

void	ft_swap_3(t_pull *stacks)
{
	if (ft_lstsize(stacks->a) == 2 && stacks->a->cont > stacks->a->next->cont)
		sa(stacks);
	if (ft_lstsize(stacks->a) == 3)
		swaps(stacks);
}
