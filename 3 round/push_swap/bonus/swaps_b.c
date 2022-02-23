/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:34:42 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:34:44 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_pull *stacks)
{
	if (!stacks->b || !stacks->b->next)
		return ;
	stacks->start_b = stacks->b;
	stacks->start_b = stacks->start_b->next;
	stacks->b->next = stacks->start_b->next;
	stacks->start_b->next = stacks->b;
	stacks->b = stacks->start_b;
}

void	rb(t_pull *stacks)
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

void	pb(t_pull *stacks)
{
	if (!stacks->a)
		return ;
	if (!stacks->a->next)
		stacks->start_a = NULL;
	else
	{
		stacks->start_a = stacks->a;
		stacks->start_a = stacks->start_a->next;
	}
	if (!stacks->b)
	{
		stacks->b = stacks->a;
		stacks->b->next = NULL;
	}
	else
	{
		stacks->a->next = stacks->b;
		stacks->b = stacks->a;
	}
	stacks->a = stacks->start_a;
}
