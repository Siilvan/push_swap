/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:52 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 18:15:18 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int		*arr;
	int		bench;
	char	*mode;

	mode = "adaptive";
	bench = 0;
	arr = parse_input(argc, argv, &mode, &bench);
	ft_printf("%d\n", bench);
	ft_printf("%s\n", mode);
	select_algo(bench, mode, arr);
	return (0);
}

void	select_algo(int bench, char *mode, int *nbrs)
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	double		disorder;
	t_oparr		*oparr;

	stack_a = get_stack_from_arr(nbrs, 5);
	stack_b = NULL;
	oparr = oparrnew();
	if (stack_a == NULL || oparr == NULL)
		error_exit(stack_a, stack_b, oparr);
	disorder = compute_disorder(stack_a);
	if (!ft_strcmp(mode, "simple"))
		algo_simple(&stack_a, &stack_b);
	else if (!ft_strcmp(mode, "medium"))
		algo_medium(&stack_a, &stack_b, oparr);
	// else if (!ft_strcmp(mode, "complex"))
	// 	algo_complex(stack_a, stack_b, oparr);
	// else if (!ft_strcmp(mode, "adaptive"))
	// 	algo_adaptive(stack_a, stack_b, oparr, disorder);
	if (bench == 1)
		bench_result(oparr, mode, disorder);
	else
		manage_result(oparr);
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

void	ft_printstack(t_intlist *stack)
{
	while (stack)
    {
        ft_printf("%d (rank %d)\n", stack->content, stack->rank);
        stack = stack->next;
    }
}