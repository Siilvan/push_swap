/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:52 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 18:26:18 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int argc, char *argv[])
// {
// 	t_userinput	*user_input;
//
// 	if (!parse_input(argc, argv, &user_input)
// 		|| !select_algo(user_input))
// 	{
// 		free(user_input);
// 		error_exit(NULL, NULL, NULL);
// 		return (1);
// 	}
// 	ft_printf("%d\n", user_input->bench);
// 	ft_printf("%s\n", user_input->mode);
// 	return (0);
// }

int	select_algo(t_userinput *user_input)
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	double		disorder;
	t_oparr		*oparr;

	stack_a = get_stack_from_arr(user_input->arr, user_input->arr_size);
	stack_b = get_stack_from_arr(user_input->arr, user_input->arr_size);
	oparr = oparrnew();
	if (!stack_a || !stack_b || !oparr)
		return (error_exit(stack_a, stack_b, oparr));
	disorder = compute_disorder(stack_a);
	if (!ft_strcmp(user_input->mode, "simple"))
		algo_simple(&stack_a, &stack_b);
	else if (!ft_strcmp(user_input->mode, "medium"))
		algo_medium(&stack_a, &stack_b, oparr);
	// else if (!ft_strcmp(mode, "complex"))
	// 	algo_complex(stack_a, stack_b, oparr);
	// else if (!ft_strcmp(mode, "adaptive"))
	// 	algo_adaptive(stack_a, stack_b, oparr, disorder);
	if (user_input->bench == 1)
		bench_result(oparr, user_input->mode, disorder);
	else
		manage_result(oparr);
	return (1);
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
