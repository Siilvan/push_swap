/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:08:50 by ngero             #+#    #+#             */
/*   Updated: 2026/10/14 14:25:22 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static void	op_swap_helper(t_intlist *stack)
{
	stack = ft_lstsecondtolast(stack);
	if (!stack)
		return ;
	ft_lstswap(stack, stack->next);
}

static void	op_push_helper(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*tmp;

	if (!stack_a)
		return ;
	if (!stack_b)
	{
		*stack_b = *stack_a;
	}
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
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
	op_push_helper(stack_a, stack_b);
}

void	op_push_b(t_intlist **stack_a, t_intlist **stack_b)
{
	ft_printf("pb");
	op_push_helper(stack_b, stack_a);
}
