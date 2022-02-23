/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:30:46 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:30:48 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s_rb(t_pull *stacks)
{
	if (!stacks->b || !stacks->b->next)
		return ;
	{
		stacks->start_b = stacks->b;
		stacks->b = stacks->b->next;
		ft_lstadd_back(&stacks->b, stacks->start_b);
		stacks->start_b->next = NULL;
	}
}

static void	s_ra(t_pull *stacks)
{
	if (!stacks->a || !stacks->a->next)
		return ;
	{
		stacks->start_a = stacks->a;
		stacks->a = stacks->a->next;
		ft_lstadd_back(&stacks->a, stacks->start_a);
		stacks->start_a->next = NULL;
	}
}

void	rr(t_pull *stacks)
{
	s_ra(stacks);
	s_rb(stacks);
	write(1, "rr\n", 3);
}
