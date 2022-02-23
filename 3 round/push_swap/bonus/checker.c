/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:52:52 by akatlyn           #+#    #+#             */
/*   Updated: 2022/01/26 20:18:15 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init(t_pull *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->start_a = NULL;
	stacks->start_b = NULL;
}

static void	input_make(t_pull *stacks, int argc, char **argv)
{
	char	*buf;
	int		gnl;

	if (argc <= 1)
		exit (0);
	else
	{
		ft_instack_a(stacks, argc, argv);
		ft_numeration(stacks);
		gnl = get_next_line(&buf);
		while (gnl)
		{
			if (gnl == -1)
				error(stacks);
			mimic(stacks, buf);
			free(buf);
			gnl = get_next_line(&buf);
		}
	}
}

int	main(int argc, char **argv)
{
	t_pull	stacks;

	init(&stacks);
	input_make(&stacks, argc, argv);
	if (ft_lstsize(stacks.b))
		error_ko(&stacks);
	final_checker(&stacks);
	finish_ok(&stacks);
	return (0);
}
