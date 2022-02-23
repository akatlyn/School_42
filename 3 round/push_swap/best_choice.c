/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:21:01 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 19:13:26 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	list_detect(t_pull *stacks, t_list *tmp_b, int num, int com)
{
	stacks->check.l_step = stacks->check.l_step + stacks->start_a->steps;
	if (stacks->start_a->com == tmp_b->com)
	{
		if (stacks->start_a->steps > tmp_b->steps)
			stacks->check.l_step -= tmp_b->steps;
		else
			stacks->check.l_step -= stacks->start_a->steps;
	}
	if (stacks->check.f_step > stacks->check.l_step
		|| stacks->check.f_step == -1)
	{
		stacks->check.f_step = stacks->check.l_step;
		stacks->check.f_ind = num;
		stacks->check.com = com;
	}
}

static	int	next_index(t_pull *stacks, int num)
{
	int	len;

	len = 1;
	while (stacks->start_b)
	{
		if (stacks->start_b->num == num + len)
		{
			stacks->start_b = stacks->b;
			len++;
		}
		else if (stacks->start_b->num != num + len)
		{
			if (!stacks->start_b->next)
				break ;
			else
				stacks->start_b = stacks->start_b->next;
		}
	}
	return (len);
}

void	ft_finder(t_pull	*stacks)
{
	int		num;
	t_list	*tmp_b;
	int		com;
	int		len;

	stacks->check.f_ind = 0;
	stacks->check.f_step = -1;
	stacks->start_b = stacks->b;
	tmp_b = stacks->b;
	while (stacks->start_b)
	{
		stacks->check.l_step = stacks->start_b->steps;
		num = stacks->start_b->num;
		com = stacks->start_b->com;
		stacks->start_b = stacks->b;
		len = next_index(stacks, num);
		tmp_b->n_ind = num + len;
		stacks->start_a = stacks->a;
		while (len + num != stacks->start_a->num)
			stacks->start_a = stacks->start_a->next;
		list_detect(stacks, tmp_b, num, com);
		tmp_b = tmp_b->next;
		stacks->start_b = tmp_b;
	}
}
