/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:24:45 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:28:23 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_spin_a(t_pull	*stacks)
{
	stacks->start_a = stacks->a;
	while (stacks->start_a->num != stacks->start_b->n_ind)
		stacks->start_a = stacks->start_a->next;
	if (stacks->start_a->com == 0)
	{
		while (stacks->a->num != stacks->b->n_ind)
			rra(stacks);
	}
	else
	{
		while (stacks->a->num != stacks->b->n_ind)
			ra(stacks);
	}
}
