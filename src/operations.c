/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:08:50 by ngero             #+#    #+#             */
/*   Updated: 2026/10/14 14:25:22 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap_helper(t_intlist *stack)
{
	if (!stack || !stack->next)
		return ;
	ft_lstswap(stack, stack->next);
}

static void	op_push_helper(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*tmp_a;
	t_intlist	*tmp_b;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	tmp_a = (*stack_a)->next;
	tmp_b = 0;
	if (*stack_b)
		tmp_b = *stack_b;
	*stack_b = *stack_a;
	(*stack_b)->next = tmp_b;
	*stack_a = tmp_a;
}

void	op_swap(t_intlist *stack_a, t_intlist *stack_b)
{
	if (stack_a && !stack_b)
		ft_printf("sa");
	else if (!stack_a && stack_b)
		ft_printf("sb");
	else if (stack_a && stack_b)
		ft_printf("ss");
	if (stack_a)
		op_swap_helper(stack_a);
	if (stack_b)
		op_swap_helper(stack_b);
}

void	op_push_a(t_intlist **stack_a, t_intlist **stack_b)
{
	ft_printf("pa");
	op_push_helper(stack_b, stack_a);
}

void	op_push_b(t_intlist **stack_a, t_intlist **stack_b)
{
	ft_printf("pb");
	op_push_helper(stack_a, stack_b);
}
