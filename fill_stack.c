/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:22:39 by kkarakus          #+#    #+#             */
/*   Updated: 2024/04/14 22:22:42 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_double_control(t_stack *stack, int content, int index)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		if (content == stack->content && index != stack->index)
			return (NULL);
		stack = stack->next;
	}
	if (content == stack->content && index != stack->index)
		return (NULL);
	return (stack);
}

static t_stack	*newstack(int index, int content)
{
	t_stack	*list_node;

	list_node = (t_stack *)malloc(sizeof(t_stack));
	if (!list_node)
		return (NULL);
	list_node -> content = content;
	list_node -> index = index;
	list_node -> next = NULL;
	list_node -> isrr = -1;
	list_node -> cost = -1;
	list_node -> target_node = NULL;
	return (list_node);
}

static void	stackadd(t_stack **stack, t_stack *tmp)
{
	if (stack_double_control(*stack, tmp->content, tmp->index) == NULL)
		print_error();
	else
		stack_double_control(*stack, tmp->content, tmp->index)->next = tmp;
}

void	ft_fill_stack(char **argv, t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	*a = newstack(i, my_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		tmp = newstack(i, my_atoi(argv[i]));
		stackadd(a, tmp);
		i++;
	}
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
