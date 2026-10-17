/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:55:54 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 10:18:07 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_medium_prt1(t_intlist **a, t_intlist **b, t_oparr *oparr)
{
	int	i;
	int	chunk_size;
	int	current_chunk;

	i = 0;
	current_chunk = 1;
	oparr->n_op = 1;
	chunk_size = ft_sqrt(ft_intlstsize(*a));
	while (*a)
	{
		if ((*a)->rank < current_chunk * chunk_size)
		{
			op_push_b(a, b);
			if ((*b)->rank < (current_chunk * chunk_size) - (chunk_size / 2))
				op_rotate(NULL, b);
			i++;
		}
		else
		{
			if (i >= current_chunk * chunk_size)
				current_chunk++;
			op_rotate(a, NULL);
		}
	}
}

void	algo_medium(t_intlist **a, t_intlist **b, t_oparr *oparr)
{
	int	nbr_amount;
	int	top_rank;

	if (!a || !b || !*a || *b)
		return ;
	nbr_amount = ft_intlstsize(*a);
	top_rank = nbr_amount - 1;
	assign_rank(*a, nbr_amount);
	algo_medium_prt1(a, b, oparr);
	while (*b)
	{
		if ((*b)->rank == top_rank)
		{
			op_push_a(a, b);
			top_rank--;
		}
		else
			op_rotate(NULL, b);
		if (top_rank < 0)
			break;
	}
	ft_printstack(*a);
}
