/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:24:05 by kkarakus          #+#    #+#             */
/*   Updated: 2024/04/16 10:08:29 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				content;
	int				isrr;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

char	**arg_join(char **argv);
char	**ft_split(char const *s, char c);
char	*my_strjoin(char *s1, char *s2);

int		is_sorted(t_stack **stack);
int		get_thelargest(t_stack **stack);
int		get_thesmallest(t_stack **stack);
int		my_atoi(const char *str);

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*get_themincost(t_stack **a);
t_stack	*nodeofindex(int index, t_stack **stack);

void	arg_check(int ac, char **argv);
void	free_stack(t_stack **a, t_stack **b);
void	ft_fill_stack(char **argv, t_stack **a);
void	gettarget(t_stack **a, t_stack **b);
void	print_error(void);
void	reindex(t_stack *stack);
void	setcost(t_stack **a, t_stack **b);
void	setrr(t_stack **stack);
void	sort_min(t_stack **a, t_stack **b, int max_index);
void	sort_it(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b);

#endif
