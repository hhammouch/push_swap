/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:54:37 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/14 01:22:17 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg_len(char **arg)
{
	int	i;

	i = 0;
	while (arg[i][0] == ' ' || arg[i][0] == '\t')
		arg[i]++;
	if (!arg[i][0])
		exit_error();
	return (1);
}

static void	check_error(char **split, t_stack **a)
{
	free_arg(split);
	if (a && *a)
        free_stack(a);
	exit_error();
}

static void	check_arg(char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (argv[i] && (check_arg_len(&argv[i])))
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (is_str_not_number(split[j]))
				check_error(split, a);
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				check_error(split, a);
			if (split[j][0] == '-' || split[j][0] == '+')
				if (split[j][1] == '\0')
					check_error(split, a);
			add_back(a, ft_atol(split[j++]));
		}
		free_arg(split);
		i++;
	}
	if (check_duplicates(*a))
		stack_error(*a, NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		if (!argv[1][0] || argv[1][0] == '\0')
			exit_error();
		check_arg(argv, &a);
		if (is_sorted(a))
			return (free_stack(&a), 0);
		else if (ft_stacksize(a) <= 3)
			sort_three(&a);
		else if (ft_stacksize(a) <= 5)
			sort_five(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	else
		return (1);
	free_stack(&a);
	return (0);
}
