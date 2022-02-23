/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:23:51 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:29:10 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_spin_b(t_pull	*stacks)
{
	stacks->start_b = stacks->b;
	while (stacks->start_b->num != stacks->check.f_ind)
		stacks->start_b = stacks->start_b->next;
	stacks->start_a = stacks->a;
	while (stacks->start_a->num != stacks->start_b->n_ind)
		stacks->start_a = stacks->start_a->next;
	if (stacks->start_a->com == stacks->start_b->com)
	{
		if (stacks->start_a->steps > stacks->start_b->steps)
			stacks->check.l_step = stacks->start_b->steps;
		else
			stacks->check.l_step = stacks->start_a->steps;
		while (stacks->check.l_step)
		{
			if (stacks->start_b->com == 1)
				rr(stacks);
			else
				rrr(stacks);
			stacks->check.l_step--;
		}
		stacks->start_b = stacks->b;
	}
}
