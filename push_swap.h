/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:55:06 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/11 18:55:46 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;


void	set_range(t_stack **a, t_stack **b);
void	stack_copy(t_stack *stack, int *arr);
int		*array_sorting(t_stack *stack, int *tab, int size);
void	index_set(t_stack **stack, int len);
void	sort_stacks(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
t_stack	*find_last(t_stack *stack);
void	rrr(t_stack **a, t_stack **b);
void	rrb(t_stack **b);
void	rra(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	sa(t_stack **a);
void	sort_stack(t_stack	**a, t_stack **b);
t_stack	*find_max_node(t_stack *a);
void	sort_three(t_stack	**a);
int		ft_stacksize(t_stack *a);
int		is_sorted(t_stack *a);
void	free_stack(t_stack **stack);
void	stack_error(t_stack *a, t_stack *b);
int		check_duplicates(t_stack *a);
void	add_back(t_stack **stack, int value);
long	ft_atol(const char *str);
void	free_arg(char **split);
int		is_str_not_number(char *str);
void	exit_error(void);

#endif