/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:52 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 11:25:00 by sgroenve         ###   ########.fr       */
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
	for (int i = 0; i < 3; i++)
	{
		ft_printf("%d\n", arr[i]);
	}
	select_algo(bench, mode, arr);
	return(0);
}

void	select_algo(int bench, char *mode, int *nbrs)
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	double		disorder;
	t_oparr		*oparr;

	stack_a = get_stack_from_arr(nbrs, sizeof(nbrs) / sizeof(int));
	stack_b = get_stack_from_arr(NULL, sizeof(nbrs) / sizeof(int));
	oparr = oparrnew();
	if (stack_a == NULL || stack_b == NULL || oparr == NULL)
		error_exit(stack_a, stack_b, oparr);
	disorder = compute_disorder(stack_a);
	if (!ft_strcmp(mode, "simple"))
		algo_simple(stack_a, stack_b, oparr);
	else if (!ft_strcmp(mode, "medium"))
		algo_medium(stack_a, stack_b, oparr);
	else if (!ft_strcmp(mode, "complex"))
		algo_complex(stack_a, stack_b, oparr);
	else if (!ft_strcmp(mode, "adaptive"))
		algo_adaptive(stack_a, stack_b, oparr, disorder);
	if (bench == 1)
		bench_result(mode, oparr, disorder);
	else
		manage_result(oparr);
}

char	*adaptive_choose(double disorder)
{
	if (disorder < 0.2)
		return ("simple");
	else if (0.2 <= disorder && disorder < 0.5)
		return ("medium");
	else if (disorder >= 0.5)
		return ("complex");
}
