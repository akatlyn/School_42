/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_oversize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:14:40 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 19:12:23 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_pull	*stacks)
{
	int		size;
	int		lst;
	int		ind;

	size = ft_lstsize(stacks->a);
	lst = size;
	while (size > 3)
	{
		ind = stacks->a->num;
		if (ind < lst - 3)
		{
			pb(stacks);
			size--;
		}
		else
			ra(stacks);
	}
	ft_swap_3(stacks);
}

void	ft_b_to_a(t_pull	*stacks)
{
	int		size;

	rotate(stacks);
	size = ft_lstsize(stacks->b);
	while (size)
	{
		lst_steps(stacks);
		ft_finder(stacks);
		ft_spin_b(stacks);
		stacks->start_b = stacks->b;
		while (stacks->start_b->num != stacks->check.f_ind)
		{
			if (stacks->check.com == 0)
				rrb(stacks);
			else
				rb(stacks);
			stacks->start_b = stacks->b;
		}
		stacks->start_b = stacks->b;
		ft_spin_a(stacks);
		pa(stacks);
		size--;
	}
}
