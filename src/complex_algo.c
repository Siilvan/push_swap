/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:46:12 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 11:47:29 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_complex(t_intlist **a, t_intlist **b)
{
	int	nbr_amount;
	int	max_bits;
	int	max_rank;
	int	i;
	int	j;

	if (!a || !b || !*a || *b)
		return ;
	nbr_amount = ft_intlstsize(*a);
	max_rank = nbr_amount - 1;
	max_bits = 0;
	i = 0;
	assign_rank(*a, nbr_amount);
	while ((max_rank >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < nbr_amount)
		{
			if ((((*a)->rank >> i) & 1) == 0)
				op_push_b(a, b);
			else
				op_rotate(a, NULL);
			j++;
		}
		while (ft_intlstsize(*b) > 0)
			op_push_a(a, b);
		i++;
	}
}
