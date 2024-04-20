/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:22:28 by kkarakus          #+#    #+#             */
/*   Updated: 2024/04/16 08:58:28 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int print)
{
	int	tmp;
	int	tmp2;

	if ((*b)->next == NULL)
		return ;
	tmp = (*b)->content;
	tmp2 = (*b)->next->content;
	(*b)->content = tmp2;
	(*b)->next->content = tmp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	rb(t_stack **b, int print)
{
	t_stack	*tmp;

	tmp = (*b)->next;
	ft_stacklast((*b))->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*tmp;
	int		lastindex;

	tmp = ft_stacklast((*b));
	lastindex = ft_stacklast((*b))->index;
	ft_stacklast((*b))->next = *b;
	while ((*b))
	{
		if ((*b)->index == lastindex - 1)
		{
			(*b)->next = NULL;
			break ;
		}
		(*b) = (*b)->next;
	}
	(*b) = tmp;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
