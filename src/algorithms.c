/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:13:38 by ngero             #+#    #+#             */
/*   Updated: 2026/10/19 19:01:06 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lstmin_and_size(t_intlist *stack_a, int *size)
{
	int	min_index;
	int	min_val;

	if (!stack_a || !size)
	{
		if (size)
			*size = 0;
		return (0);
	}
	min_index = 0;
	*size = 0;
	min_val = stack_a->content;
	while (stack_a)
	{
		if (stack_a->content < min_val)
		{
			min_index = *size;
			min_val = stack_a->content;
		}
		(*size)++;
		stack_a = stack_a->next;
	}
	return (min_index);
}

void	algo_simple(t_intlist **stack_a, t_intlist **stack_b, t_oparr **oparr)
{
	int	min_index;
	int	a_size;

	if (!stack_a || !stack_b || !*stack_a || *stack_b)
		return ;
	while (*stack_a)
	{
		min_index = ft_lstmin_and_size(*stack_a, &a_size);
		if (min_index < a_size / 2)
			while (min_index--)
				op_rotate(stack_a, NULL, oparr);
		else
			while (a_size - min_index++)
				op_reverse_rotate(stack_a, NULL, oparr);
		op_push_b(stack_a, stack_b, oparr);
	}
	while (*stack_b)
		op_push_a(stack_a, stack_b, oparr);
}

void	algo_adaptive(t_intlist **a, t_intlist **b, t_oparr **ops,
			double disorder)
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
