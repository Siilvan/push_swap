/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:52 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 17:11:27 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_userinput	*user_input;

	if (!parse_input(argc, argv, &user_input)
		|| !select_algo(user_input))
	{
		free(user_input);
		error_exit(NULL, NULL, NULL);
		return (1);
	}
	free(user_input);
	return (0);
}

int	select_algo(t_userinput *user_input)
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	double		disorder;
	t_oparr		*oparr;

	stack_a = get_stack_from_arr(user_input->arr, user_input->arr_size);
	stack_b = NULL;
	oparr = oparrnew();
	if (stack_a == NULL || oparr == NULL)
		error_exit(&stack_a, &stack_b, &oparr);
	disorder = compute_disorder(stack_a);
	if (!ft_strcmp(user_input->mode, "simple"))
		algo_simple(&stack_a, &stack_b, &oparr);
	else if (!ft_strcmp(user_input->mode, "medium"))
		algo_medium(&stack_a, &stack_b, &oparr);
	else if (!ft_strcmp(user_input->mode, "complex"))
		algo_complex(&stack_a, &stack_b, &oparr);
	else if (!ft_strcmp(user_input->mode, "adaptive"))
		algo_adaptive(&stack_a, &stack_b, &oparr, disorder);
	if (user_input->bench == 1)
		bench_result(&oparr, user_input->mode, disorder);
	manage_result(&oparr);
	return (1);
}
