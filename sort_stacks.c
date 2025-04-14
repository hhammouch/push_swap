/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:53:52 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/13 19:31:22 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_sorting(t_stack *stack, int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	stack_copy(stack, tab);
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	index_set(t_stack **stack, int len)
{
	int		i;
	int		*arr;
	t_stack	*temp;

	temp = *stack;
	arr = malloc(len * sizeof(int));
	if (!arr)
		return ;
	array_sorting(*stack, arr, len);
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == temp->value)
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
	free (arr);
}

void	set_range(t_stack **a, t_stack **b)
{
	int	min_rang;
	int	max_rang;

	min_rang = 0;
	if (ft_stacksize(*a) > 15)
		max_rang = 0.045 * ft_stacksize(*a) + 10;
	else
		max_rang = 0.045 * ft_stacksize(*a);
	while (*a)
	{
		if ((*a)->index > max_rang)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->index < min_rang)
				rb(b);
			min_rang++;
			max_rang++;
		}
	}
}

static int	max_value(t_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = ft_stacksize(stack) - 1;
	while (stack)
	{
		if (index == stack->index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (index);
}

// void    print_stack(t_stack *stack, char *name)
// {
//         t_stack *tmp;

//         tmp = stack;
//         write(1, name, ft_strlen(name));
//         write(1, ": ", 2);
//         while (tmp)
//         {
//                 ft_putnbr_fd(tmp->value, 1);
//                 write(1, " ", 1);
//                 tmp = tmp->next;
//         }
//         write(1, "\n", 1);
// }


void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size;
	int	index;

	size = ft_stacksize(*a);
	index_set(a, size);
	set_range(a, b);
	//print_stack(*b, "Stack B");
	while (*b)
	{
		size = ft_stacksize(*b);
		index = max_value(*b);
		//printf("INDEX => %d\n", index);
		if (index == 0)
			pa(a, b);
		else if (index > (size / 2) && index != 0)
			rrb(b);
		else if (index <= (size / 2) && index != 0)
			rb(b);
		//print_stack(*b, "Stack B");
		//print_stack(*a, "Stack A");
	}
	//print_stack(*a, "Stack A");
	free_stack(a);
}
