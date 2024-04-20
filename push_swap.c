/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:23:17 by kkarakus          #+#    #+#             */
/*   Updated: 2024/04/16 11:35:37 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	is_arg_only_space(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || arg[i] == '-'
			|| arg[i] == '+')
			return (1);
		i++;
	}
	print_error();
	return (0);
}

static void	int_check(int ac, char **av)
{
	int	i;

	if (ac < 2)
		exit(0);
	i = 1;
	while (av[i])
	{
		my_atoi(av[i]);
		is_arg_only_space(av[i]);
		i++;
	}
}

static void	ft_sort(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
	{
		free_stack(a, b);
		exit(0);
	}
	if (ft_stacklast(*a)->index < 5)
		sort_min(a, b, ft_stacklast(*a)->index);
	else
	{
		setrr(a);
		setcost(a, b);
		sort_it(a, b);
		free_stack(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	**arg_ar;

	int_check(argc, argv);
	arg_check(argc, argv);
	b = malloc(sizeof(t_stack *));
	a = malloc(sizeof(t_stack *));
	arg_ar = arg_join(argv);
	ft_fill_stack(arg_ar, a);
	free_split(arg_ar);
	ft_sort(a, b);
	free(a);
	free(b);
}

// __attribute__((destructor))
// static void	test(void)
// {
// 	system("leaks push_swap");
// }
