/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:12:25 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/12 22:41:04 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_numeration(t_pull *stacks)
{
	if (stacks->start_a->num != 0)
		return ;
	while (stacks->start_a->next)
	{
		if (stacks->start_a->num + 1 != stacks->start_a->next->num)
			return ;
		stacks->start_a = stacks->start_a->next;
	}
	stacks->start_a = stacks->a;
	ft_lstclear(&stacks->a);
	exit (0);
}
