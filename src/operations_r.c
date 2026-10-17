/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:41:10 by ngero             #+#    #+#             */
/*   Updated: 2026/10/17 13:45:26 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rrotate_helper(t_intlist **stack)
{
	t_intlist	*last;
	t_intlist	*second_to_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_intlstlast(*stack);
	second_to_last = ft_lstsecondtolast(*stack);
	last->next = *stack;
	second_to_last->next = 0;
	*stack = last;
}

static void	op_rotate_helper(t_intlist **stack)
{
	t_intlist	*last;
	t_intlist	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	last = ft_intlstlast(*stack);
	last->next = *stack;
	(*stack)->next = 0;
	*stack = tmp;
}

void	op_rotate(t_intlist **stack_a, t_intlist **stack_b, t_oparr **oparr)
{
	if (stack_a && !stack_b)
		ft_add_op(oparr, RA);
	else if (!stack_a && stack_b)
		ft_add_op(oparr, RB);
	else if (stack_a && stack_b)
		ft_add_op(oparr, RR);
	if (stack_a)
		op_rotate_helper(stack_a);
	if (stack_b)
		op_rotate_helper(stack_b);
}

void	op_reverse_rotate(t_intlist **stack_a, t_intlist **stack_b,
				t_oparr **oparr)
{
	if (stack_a && !stack_b)
		ft_add_op(oparr, RRA);
	else if (!stack_a && stack_b)
		ft_add_op(oparr, RRB);
	else if (stack_a && stack_b)
		ft_add_op(oparr, RRR);
	if (stack_a)
		op_rrotate_helper(stack_a);
	if (stack_b)
		op_rrotate_helper(stack_b);
}
