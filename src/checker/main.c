/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:11:21 by ngero             #+#    #+#             */
/*   Updated: 2026/10/19 20:14:08 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_intlist	*get_stack_from_input(int ac, char **av)
{
	int			*arr;
	t_intlist	*stack;

	if (ac < 2)
		return (0);
	if (!get_numbers_array(ac - 1, &av[1], &arr))
		return (0);
	stack = get_stack_from_arr(arr, ac - 1);
	free(arr);
	return (stack);
}

int	is_stack_in_order(t_intlist *stack)
{
	t_intlist	*sk;

	while (stack)
	{
		sk = stack->next;
		while (sk)
		{
			if (sk->content < stack->content)
				return (0);
			sk = sk->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	check_stacks(t_intlist *stack_a, t_intlist *stack_b)
{
	if (!stack_a || stack_b)
		return (0);
	return (is_stack_in_order(stack_a));
}

int	main(int ac, char **av)
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	char		*line;

	stack_a = get_stack_from_input(ac, av);
	stack_b = NULL;
	if (!stack_a)
		return (checker_exit("Error\n", 1));
	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(&stack_a, &stack_b, line))
			return (checker_exit("Error\n", 1));
		free(line);
		line = get_next_line(0);
	}
	if (!check_stacks(stack_a, stack_b))
		return (checker_exit("KO\n", 1));
	return (checker_exit("OK\n", 0));
}
