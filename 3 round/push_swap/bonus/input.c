/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:08:11 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/14 19:16:20 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	freeshing(char **mass, int count)
{
	while (count)
		free(mass[--count]);
	free(mass);
	mass = NULL;
}

void	ft_instack_a(t_pull *stacks, int argc, char **argv)
{
	char	**mass;
	int		i;
	int		j;
	int		cont;

	i = 1;
	while (argc > i)
	{
		mass = ft_split(argv[i++], ' ');
		j = 0;
		while (mass[j])
		{
			cont = ft_atoi(mass[j++]);
			stacks->start_a = stacks->a;
			while (stacks->start_a)
			{
				if (stacks->start_a->cont == cont)
					error(stacks);
				stacks->start_a = stacks->start_a->next;
			}
			stacks->start_a = ft_lstnew(cont);
			ft_lstadd_back(&stacks->a, stacks->start_a);
		}
		freeshing(mass, j);
	}
}
