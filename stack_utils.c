/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:58:04 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/13 17:33:51 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_node(t_stack *a)
{
	int		max;
	t_stack	*temp;
	t_stack	*max_node;

	temp = a;
	max = temp->value;
	max_node = temp;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

void	add_back(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

int	ft_stacksize(t_stack *a)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = a;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	stack_copy(t_stack *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
}
