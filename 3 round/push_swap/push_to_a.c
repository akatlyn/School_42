/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:26:30 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 19:20:29 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_pull	*stacks)
{
	stacks->check.f_ind = 0;
	stacks->check.n_ind = ft_lstsize(stacks->a);
	stacks->start_a = stacks->a;
	while (stacks->start_a->num)
	{
		stacks->start_a = stacks->start_a->next;
		stacks->check.f_ind++;
	}
	stacks->start_a = stacks->a;
	if (stacks->check.f_ind > stacks->check.n_ind / 2 + stacks->check.n_ind % 2)
	{
		while (stacks->start_a->num)
		{
			rra(stacks);
			stacks->start_a = stacks->a;
		}
	}
	while (stacks->start_a->num)
	{
		ra(stacks);
		stacks->start_a = stacks->a;
	}
}
