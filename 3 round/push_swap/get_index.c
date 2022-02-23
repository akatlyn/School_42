/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:11:10 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 19:41:03 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_indexation(t_pull *stacks, int *numbs, int c_lst)
{
	int		swap;
	int		i;

	i = 0;
	while (i < c_lst - 1)
	{
		if (numbs[i] > numbs[i + 1])
		{
			swap = numbs[i];
			numbs[i] = numbs [i + 1];
			numbs[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (i <= c_lst - 1)
	{
		stacks->start_a = stacks->a;
		while (numbs[i] != stacks->start_a->cont)
			stacks->start_a = stacks->start_a->next;
		stacks->start_a->num = i++;
	}
}

void	ft_numeration(t_pull *stacks)
{
	int		*numbs;
	int		*tmp;
	int		c_lst;

	c_lst = ft_lstsize(stacks->a);
	numbs = malloc(sizeof(int) * c_lst);
	if (!numbs)
		error(stacks);
	tmp = numbs;
	stacks->start_a = stacks->a;
	while (stacks->start_a)
	{
		*tmp++ = stacks->start_a->cont;
		stacks->start_a = stacks->start_a->next;
	}
	ft_indexation(stacks, numbs, c_lst);
	free(numbs);
}
