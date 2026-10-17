/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:13:38 by ngero             #+#    #+#             */
/*   Updated: 2026/10/17 16:29:07 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_simple(t_intlist **stack_a, t_intlist **stack_b, t_oparr **oparr)
{
	int	bsize;
	int	i;

	if (!stack_a || !stack_b || !*stack_a || *stack_b)
		return ;
	op_push_b(stack_a, stack_b, oparr);
	bsize = 1;
	while (*stack_a)
	{
		i = 0;
		while ((*stack_a)->content < (*stack_b)->content && i < bsize)
		{
			op_rotate(NULL, stack_b, oparr);
			i++;
		}
		op_push_b(stack_a, stack_b, oparr);
		while (i-- > 0)
			op_reverse_rotate(NULL, stack_b, oparr);
		bsize++;
	}
	while (*stack_b)
		op_push_a(stack_a, stack_b, oparr);
}

void	algo_adaptive(t_intlist **a, t_intlist **b, t_oparr **ops, int disorder)
{
	if (disorder < 0.2)
		algo_simple(a, b, ops);
	else if (0.2 <= disorder && disorder < 0.5)
		algo_medium(a, b, ops);
	else
		algo_complex(a, b, ops);
}

char	*adaptive_choose(double disorder)
{
	if (disorder < 0.2)
		return ("simple");
	else if (0.2 <= disorder && disorder < 0.5)
		return ("medium");
	else
		return ("complex");
}