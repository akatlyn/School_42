/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:27:39 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:27:41 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				cont;
	int				num;
	int				steps;
	int				com;
	int				f_ind;
	int				n_ind;
	int				f_step;
	int				l_step;
	struct s_list	*next;
}					t_list;

typedef struct s_pull
{
	t_list		*a;
	t_list		*b;
	t_list		*start_a;
	t_list		*start_b;
	t_list		check;
}				t_pull;

void	ft_init(t_pull *stacks);
void	ft_instack_a(t_pull *stacks, int argc, char **argv);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
void	error(t_pull *stacks);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	sa(t_pull *stacks);
void	ra(t_pull *stacks);
void	pa(t_pull *stacks);
void	rra(t_pull *stacks);
void	sb(t_pull *stacks);
void	rb(t_pull *stacks);
void	pb(t_pull *stacks);
void	rrb(t_pull *stacks);
void	ss(t_pull *stacks);
void	rr(t_pull *stacks);
void	rrr(t_pull *stacks);
void	ft_swap_3(t_pull *stacks);
void	ft_push_a(t_pull	*stacks);
void	ft_numeration(t_pull *stacks);
void	ft_instack_a(t_pull *stacks, int argc, char **argv);
void	check_numeration(t_pull *stacks);
void	ft_b_to_a(t_pull	*stacks);
void	lst_steps(t_pull	*stacks);
void	ft_finder(t_pull	*stacks);
void	ft_spin_a(t_pull	*stacks);
void	ft_spin_b(t_pull	*stacks);

#endif