/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:52 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/19 18:59:42 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char *argv[])
// {
// 	if (!sort_stack(argc, argv))
// 		return (1);
// 	return (0);
// }

int	sort_stack(int argc, char *argv[])
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	t_oparr		*oparr;
	t_userinput	*user_input;

	stack_a = 0;
	stack_b = 0;
	oparr = 0;
	user_input = 0;
	if (!parse_input(argc, argv, &user_input)
		|| !select_algo(&stack_a, &stack_b, &oparr, &user_input))
		return (error_exit(&stack_a, &stack_b, &oparr, &user_input));
	ft_cleanup(&stack_a, &stack_b, &oparr, &user_input);
	return (1);
}

int	select_algo(t_intlist **stack_a, t_intlist **stack_b, t_oparr **oparr,
		t_userinput **user_input)
{
	double		disorder;

	*stack_a = get_stack_from_arr((*user_input)->arr, (*user_input)->arr_size);
	*stack_b = NULL;
	*oparr = oparrnew();
	if (*stack_a == NULL || *oparr == NULL)
		return (0);
	disorder = compute_disorder(*stack_a);
	if (!ft_strcmp((*user_input)->mode, "simple") && disorder)
		algo_simple(stack_a, stack_b, oparr);
	else if (!ft_strcmp((*user_input)->mode, "medium") && disorder)
		algo_medium(stack_a, stack_b, oparr);
	else if (!ft_strcmp((*user_input)->mode, "complex") && disorder)
		algo_complex(stack_a, stack_b, oparr);
	else if (!ft_strcmp((*user_input)->mode, "adaptive") && disorder)
		algo_adaptive(stack_a, stack_b, oparr, disorder);
	if ((*user_input)->bench == 1)
		bench_result(oparr, (*user_input)->mode, disorder, TESTING);
	manage_result(oparr, TESTING);
	return (1);
}
