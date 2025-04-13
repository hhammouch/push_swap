/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:40:21 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/13 17:43:19 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*get_last(t_stack *stack, int before_last)
{
	if (!stack)
		return (NULL);
	if (before_last)
	{
		if (!stack->next)
			return (NULL);
		while (stack->next->next)
			stack = stack->next;
	}
	else
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last(*stack, 0);
	before_last = get_last(*stack, 1);
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}

void	reverse_rotate_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
