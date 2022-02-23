/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:08:43 by akatlyn           #+#    #+#             */
/*   Updated: 2021/11/13 23:49:14 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	init(t_pull *stacks)
{
	stacks->a = 0;
	stacks->b = 0;
	stacks->start_a = 0;
	stacks->start_b = 0;
}

int	main(int argc, char **argv)
{
	t_pull		stacks;
	int			a;

	a = 0;
	init(&stacks);
	ft_instack_a(&stacks, argc, argv);
	stacks.start_a = stacks.a;
	if (ft_lstsize(stacks.a) <= 3)
		ft_swap_3(&stacks);
	else
	{
		ft_numeration(&stacks);
		stacks.start_a = stacks.a;
		check_numeration(&stacks);
		ft_b_to_a(&stacks);
		ft_push_a(&stacks);
	}
	ft_lstclear(&stacks.a);
	return (0);
}
