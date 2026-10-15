/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:08:50 by ngero             #+#    #+#             */
/*   Updated: 2026/10/15 14:09:52 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap_helper(t_intlist *stack)
{
	stack = ft_lstsecondtolast(stack);
	if (!stack)
		return ;
	ft_lstswap(stack, stack->next);
}

static void	op_push_helper(t_intlist *stack_a, t_intlist *stack_b)
{
	t_intlist	*last_a;
	t_intlist	*last_b;

	if (!stack_a || !stack_b)
		return ;
	last_a = ft_intlstlast(stack_a);
	last_b = ft_intlstlast(stack_b);
	last_a->next = last_b;
	last_b = ft_lstsecondtolast(stack_b);
	if (last_b)
		last_b->next = 0;
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

void	op_push_a(t_intlist *stack_a, t_intlist *stack_b)
{
	ft_printf("pa");
	op_push_helper(stack_a, stack_b);
}

void	op_push_b(t_intlist *stack_a, t_intlist *stack_b)
{
	ft_printf("pb");
	op_push_helper(stack_b, stack_a);
}
