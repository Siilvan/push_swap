/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:02:21 by ngero             #+#    #+#             */
/*   Updated: 2026/10/21 15:02:59 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker_exit(const char *n, int code, t_intlist **stack_a,
		t_intlist **stack_b)
{
	if (stack_a)
		ft_intlstclear(stack_a);
	if (stack_b)
		ft_intlstclear(stack_b);
	if (code == 1)
		ft_fdprintf(2, "%s", n);
	else
		ft_fdprintf(1, "%s", n);
	return (code);
}

int	execute_operation(t_intlist **stack_a, t_intlist **stack_b, const char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		return (op_swap(*stack_a, NULL, NULL), 1);
	if (!ft_strcmp(op, "sb\n"))
		return (op_swap(NULL, *stack_b, NULL), 1);
	if (!ft_strcmp(op, "ss\n"))
		return (op_swap(*stack_a, *stack_b, NULL), 1);
	if (!ft_strcmp(op, "pa\n"))
		return (op_push_a(stack_a, stack_b, NULL), 1);
	if (!ft_strcmp(op, "pb\n"))
		return (op_push_b(stack_a, stack_b, NULL), 1);
	if (!ft_strcmp(op, "ra\n"))
		return (op_rotate(stack_a, NULL, NULL), 1);
	if (!ft_strcmp(op, "rb\n"))
		return (op_rotate(NULL, stack_b, NULL), 1);
	if (!ft_strcmp(op, "rr\n"))
		return (op_rotate(stack_a, stack_b, NULL), 1);
	if (!ft_strcmp(op, "rra\n"))
		return (op_reverse_rotate(stack_a, NULL, NULL), 1);
	if (!ft_strcmp(op, "rrb\n"))
		return (op_reverse_rotate(NULL, stack_b, NULL), 1);
	if (!ft_strcmp(op, "rrr\n"))
		return (op_reverse_rotate(stack_a, stack_b, NULL), 1);
	return (0);
}
