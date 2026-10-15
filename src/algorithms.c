/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:13:38 by ngero             #+#    #+#             */
/*   Updated: 2026/10/14 14:26:22 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_simple(t_intlist **stack_a, t_intlist **stack_b)
{
	// t_intlist	*max_a;
	// int			d_to_top;

	if (!stack_a || !stack_b || !*stack_a || *stack_b)
		return ;
	op_swap(*stack_a, *stack_b);
	op_push_b(stack_a, stack_b);
	op_swap(*stack_a, *stack_b);
}
