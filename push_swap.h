/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:55:06 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/03 16:19:14 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void	add_back(t_stack **stack, int value);
long	ft_atol(const char *str);
void	free_arg(char **split);
int		is_str_not_number(char *str);
void	exit_error(void);

#endif