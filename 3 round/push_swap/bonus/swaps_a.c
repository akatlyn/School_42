/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:34:08 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:34:17 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_pull *stacks)
{
	if (!stacks->a || !stacks->a->next)
		return ;
	stacks->start_a = stacks->a;
	stacks->start_a = stacks->start_a->next;
	stacks->a->next = stacks->start_a->next;
	stacks->start_a->next = stacks->a;
	stacks->a = stacks->start_a;
}

void	ra(t_pull *stacks)
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

void	pa(t_pull *stacks)
{
	if (!stacks->b)
		return ;
	if (!stacks->b->next)
		stacks->start_b = NULL;
	else
	{
		stacks->start_b = stacks->b;
		stacks->start_b = stacks->start_b->next;
	}
	if (!stacks->a)
	{
		stacks->a = stacks->b;
		stacks->a->next = NULL;
	}
	else
	{
		stacks->b->next = stacks->a;
		stacks->a = stacks->b;
	}
	stacks->b = stacks->start_b;
}
