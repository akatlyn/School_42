/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:21:54 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:21:55 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*new;

	if (lst)
	{
		while (*lst)
		{
			new = (*lst)->next;
			ft_lstdelone(*lst);
			*lst = new;
		}
		*lst = NULL;
	}
}
