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
#include <stdlib.h>

void	algo_simple(t_intlist *stack_a, t_intlist *stack_b)
{
	t_intlist	*max_a;
	int			d_to_top;

	if (!stack_a || stack_b)
		return ;

	while (stack_a->content < stack_b->content)
		op_swap(NULL, stack_b);

		op_push_b(&stack_a, &stack_b);
}
