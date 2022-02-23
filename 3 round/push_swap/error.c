/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:27:12 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/12 22:27:19 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_pull *stacks)
{
	ft_lstclear(&stacks->a);
	ft_lstclear(&stacks->b);
	write(1, "error input\n", 13);
	exit(1);
}
