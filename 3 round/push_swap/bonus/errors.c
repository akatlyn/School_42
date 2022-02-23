/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:27:12 by akatlyn           #+#    #+#             */
/*   Updated: 2021/11/13 23:03:31 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	finish_ok(t_pull	*stacks)
{
	write(1, "OK\n", 3);
	ft_lstclear(&stacks->a);
}

void	error_ko(t_pull *stacks)
{
	ft_lstclear(&stacks->a);
	ft_lstclear(&stacks->b);
	write(2, "KO\n", 3);
	exit (1);
}

void	error(t_pull *stacks)
{
	ft_lstclear(&stacks->a);
	ft_lstclear(&stacks->b);
	write(1, "Error\n", 6);
	exit (1);
}
