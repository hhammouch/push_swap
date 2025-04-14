/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:29:00 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/14 01:04:51 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	swap(t_stack **stack)
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

void	sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
