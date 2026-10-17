/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:46:12 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 14:09:03 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_inner_loop(t_intlist **a, t_intlist **b, t_oparr **ops, int bit)
{
	int	j;
	int	i;
	int	nbr_amount;

	i = 0;
	nbr_amount = ft_intlstsize(*a);
	while (i < bit)
	{
		j = 0;
		while (j < nbr_amount)
		{
			if ((((*a)->rank >> i) & 1) == 0)
				op_push_b(a, b, ops);
			else
				op_rotate(a, NULL, ops);
			j++;
		}
		while (ft_intlstsize(*b) > 0)
			op_push_a(a, b, ops);
		i++;
	}
}

void	algo_complex(t_intlist **a, t_intlist **b, t_oparr **oparr)
{
	int	max_bits;
	int	max_rank;
	int	nbr_amount;

	if (!a || !b || !*a || *b)
		return ;
	nbr_amount = ft_intlstsize(*a);
	max_rank = nbr_amount - 1;
	max_bits = 0;
	assign_rank(*a, nbr_amount);
	while ((max_rank >> max_bits) != 0)
		max_bits++;
	complex_inner_loop(a, b, oparr, max_bits);
}
