/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:54:37 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/03 19:08:07 by hhammouc         ###   ########.fr       */
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
static void	check_error(char **split)
{
	free_arg(split);
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
				check_error(split);
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				check_error(split);
			if (split[j][0] == '-' || split[j][0] == '+')
				if (split[j][1] == '\0')
					check_error(split);
			add_back(a, ft_atol(split[j++]));
		}
		free_arg(split);
		i++;
	}
	
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
		while(a)
		{
			printf("%d|",a->value);
			a = a->next;
		}
	}
}
