/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:22:53 by kkarakus          #+#    #+#             */
/*   Updated: 2024/04/16 08:58:43 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((*b) == NULL)
		return ;
	tmp2 = (*b);
	tmp = (*b)->next;
	tmp2->next = (*a);
	(*a) = tmp2;
	(*b) = tmp;
	reindex((*a));
	reindex((*b));
	setrr(a);
	setrr(b);
	setcost(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((*a) == NULL)
		return ;
	tmp2 = (*a);
	tmp = (*a)->next;
	tmp2->next = (*b);
	(*b) = tmp2;
	(*a) = tmp;
	reindex((*a));
	reindex((*b));
	setrr(a);
	setrr(b);
	setcost(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		sa(a, 0);
		sb(b, 0);
		ft_putstr_fd("ss\n", 1);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ra(a, 0);
		rb(b, 0);
		ft_putstr_fd("rr\n", 1);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		rra(a, 0);
		rrb(b, 0);
		ft_putstr_fd("rrr\n", 1);
	}
}
