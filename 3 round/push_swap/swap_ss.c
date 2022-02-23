/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:33:41 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:34:01 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s_sa(t_pull *stacks)
{
	if (!stacks->a || !stacks->a->next)
		return ;
	stacks->start_a = stacks->a;
	stacks->start_a = stacks->start_a->next;
	stacks->a->next = stacks->start_a->next;
	stacks->start_a->next = stacks->start_a;
	stacks->a = stacks->start_a;
}

static void	s_sb(t_pull *stacks)
{
	if (!stacks->b || !stacks->b->next)
		return ;
	stacks->start_b = stacks->a;
	stacks->start_b = stacks->start_b->next;
	stacks->b->next = stacks->start_b->next;
	stacks->start_b->next = stacks->start_b;
	stacks->b = stacks->start_b;
}

void	ss(t_pull *stacks)
{
	s_sa(stacks);
	s_sb(stacks);
	write(1, "ss\n", 3);
}
