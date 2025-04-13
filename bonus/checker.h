/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:43:30 by hhammouc          #+#    #+#             */
/*   Updated: 2025/04/12 12:49:47 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../libft/libft.h"
# include "gnl/get_next_line.h"

void	args_check(char **argv, t_stack **a);
void	push(t_stack **src, t_stack **dst);
void	reverse_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **stack);
void	swap_ss(t_stack **a, t_stack **b);
void	rotate_rr(t_stack **a, t_stack **b);
void	reverse_rotate_rrr(t_stack **a, t_stack **b);

#endif