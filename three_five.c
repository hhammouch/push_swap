/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:30:34 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/11 18:05:22 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*large_n;

	large_n = find_max_node(*a);
	if (large_n == *a && ft_stacksize(*a) == 3)
		ra(a);
	else if ((*a)->next == large_n && ft_stacksize(*a) == 3)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static int	min_pos_finder(t_stack *stack)
{
	int	min_p;
	int	min_val;
	int	pos;
	
	min_p = 0;
	min_val = stack->value;
	pos = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_p = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_p);
}

static void	min_move_to_top(t_stack **stack)
{
	int	min_pos;
	int	len;

	min_pos = min_pos_finder(*stack);
	len = ft_stacksize(*stack);
	if (min_pos <= len / 2)
		while (min_pos--)
			ra(stack);
	else
		while (min_pos++ < len)
			rra(stack);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	len;
	
	len = ft_stacksize(*a);
	if (len > 5 || len < 4)
		return ;
	min_move_to_top(a);
	pb(a, b);
	if (len == 5)
	{
		min_move_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	if (len == 5)
		pa(a, b);
}
