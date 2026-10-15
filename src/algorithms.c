/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:13:38 by ngero             #+#    #+#             */
/*   Updated: 2026/10/15 18:33:33 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_simple(t_intlist **stack_a, t_intlist **stack_b)
{
	int	bsize;
	int	i;

	if (!stack_a || !stack_b || !*stack_a || *stack_b)
		return ;
	op_push_b(stack_a, stack_b);
	bsize = 1;
	while (*stack_a)
	{
		i = 0;
		while ((*stack_a)->content < (*stack_b)->content && i < bsize)
		{
			op_rotate(NULL, stack_b);
			i++;
		}
		op_push_b(stack_a, stack_b);
		while (i-- > 0)
			op_reverse_rotate(NULL, stack_b);
		bsize++;
	}
	while (*stack_b)
		op_push_a(stack_a, stack_b);
}
