/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:36:09 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/14 01:04:27 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last_node = find_last(*stack);
	*stack = first->next;
	last_node->next = first;
	first->next = NULL;
}

void	rotate_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*stack = temp2;
}

void	swap_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
