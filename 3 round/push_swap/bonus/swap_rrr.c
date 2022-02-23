/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:33:13 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:33:14 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	s_rra(t_pull *stacks)
{
	t_list	*tmp;

	if (!stacks->a || !stacks->a->next)
		return ;
	stacks->start_a = stacks->a;
	while (stacks->start_a->next->next)
		stacks->start_a = stacks->start_a->next;
	tmp = stacks->start_a->next;
	stacks->start_a->next = NULL;
	tmp->next = stacks->a;
	stacks->a = tmp;
}

static void	s_rrb(t_pull *stacks)
{
	t_list	*tmp;

	if (!stacks->b || !stacks->b->next)
		return ;
	stacks->start_b = stacks->b;
	while (stacks->start_b->next->next)
		stacks->start_b = stacks->start_b->next;
	tmp = stacks->start_b->next;
	stacks->start_b->next = NULL;
	tmp->next = stacks->b;
	stacks->b = tmp;
}

void	rra(t_pull *stacks)
{
	t_list	*tmp;

	if (!stacks->a || !stacks->a->next)
		return ;
	stacks->start_a = stacks->a;
	while (stacks->start_a->next->next)
		stacks->start_a = stacks->start_a->next;
	tmp = stacks->start_a->next;
	stacks->start_a->next = NULL;
	tmp->next = stacks->a;
	stacks->a = tmp;
}

void	rrb(t_pull *stacks)
{
	t_list	*tmp;

	if (!stacks->b || !stacks->b->next)
		return ;
	stacks->start_b = stacks->b;
	while (stacks->start_b->next->next)
		stacks->start_b = stacks->start_b->next;
	tmp = stacks->start_b->next;
	stacks->start_b->next = NULL;
	tmp->next = stacks->b;
	stacks->b = tmp;
}

void	rrr(t_pull *stacks)
{
	s_rra(stacks);
	s_rrb(stacks);
}
