/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mimic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:58:36 by akatlyn           #+#    #+#             */
/*   Updated: 2021/11/23 20:58:37 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	mimic(t_pull *stacks, char *line)
{
	if (ft_strcmp(line, "rra"))
		rra(stacks);
	else if (ft_strcmp(line, "rrb"))
		rrb(stacks);
	else if (ft_strcmp(line, "rrr"))
		rrr(stacks);
	else if (ft_strcmp(line, "sa"))
		sa(stacks);
	else if (ft_strcmp(line, "sb"))
		sb(stacks);
	else if (ft_strcmp(line, "ra"))
		ra(stacks);
	else if (ft_strcmp(line, "rb"))
		rb(stacks);
	else if (ft_strcmp(line, "pa"))
		pa(stacks);
	else if (ft_strcmp(line, "pb"))
		pb(stacks);
	else if (ft_strcmp(line, "rr"))
		rr(stacks);
	else if (ft_strcmp(line, "ss"))
		ss(stacks);
	else
		error(stacks);
}
