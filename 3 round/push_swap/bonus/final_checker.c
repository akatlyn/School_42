/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:26:09 by akatlyn           #+#    #+#             */
/*   Updated: 2021/11/23 21:03:36 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	final_checker(t_pull *stacks)
{
	stacks->start_a = stacks->a;
	while (stacks->start_a->next != NULL)
	{
		if (stacks->start_a->num + 1 == stacks->start_a->next->num)
			stacks->start_a = stacks->start_a->next;
		else
			error_ko(stacks);
	}
}
