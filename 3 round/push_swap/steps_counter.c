/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:18:45 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 19:21:50 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	steps_b(t_pull	*stacks)
{
	int		sum;
	int		count;
	int		steps;

	count = 0;
	steps = 0;
	sum = ft_lstsize(stacks->b);
	stacks->start_b = stacks->b;
	while ((sum / 2 + sum % 2) > count)
	{
		stacks->start_b->steps = steps++;
		stacks->start_b->com = 1;
		count++;
		stacks->start_b = stacks->start_b->next;
	}
	if (!(sum % 2))
		steps++;
	while (stacks->start_b)
	{
		stacks->start_b->steps = --steps;
		stacks->start_b->com = 0;
		stacks->start_b = stacks->start_b->next;
	}
}

static	void	steps_a(t_pull	*stacks)
{
	int		sum;
	int		count;
	int		steps;

	count = 0;
	steps = 0;
	sum = ft_lstsize(stacks->a);
	stacks->start_a = stacks->a;
	while ((sum / 2 + sum % 2) > count)
	{
		stacks->start_a->steps = steps++;
		stacks->start_a->com = 1;
		count++;
		stacks->start_a = stacks->start_a->next;
	}
	if (!(sum % 2))
		steps++;
	while (stacks->start_a)
	{
		stacks->start_a->steps = --steps;
		stacks->start_a->com = 0;
		stacks->start_a = stacks->start_a->next;
	}
}

void	lst_steps(t_pull	*stacks)
{
	steps_a(stacks);
	steps_b(stacks);
}
