/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:55:54 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/19 11:08:13 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(int size)
{
	if (size <= 100)
		return (size / 4);
	else if (size <= 500)
		return (size / 10);
	else
		return (size / 15);
}

void	assign_chunks(t_intlist **a, t_intlist **b, t_oparr **oparr)
{
	int	i;
	int	chunk_size;
	int	current_chunk;

	i = 0;
	current_chunk = 1;
	chunk_size = ft_sqrt(ft_intlstsize(*a));
	while (*a)
	{
		if ((*a)->rank < current_chunk * chunk_size)
		{
			op_push_b(a, b, oparr);
			if ((*b)->rank < (current_chunk * chunk_size) - (chunk_size / 2))
				op_rotate(NULL, b, oparr);
			i++;
		}
		else
		{
			if (i >= current_chunk * chunk_size)
				current_chunk++;
			op_rotate(a, NULL, oparr);
		}
	}
}

int	find_index(t_intlist *stack, int target)
{
	int			idx;
	t_intlist	*temp;

	temp = stack;
	idx = 0;
	while (temp)
	{
		if (temp->rank == target)
			return (idx);
		temp = temp->next;
		idx++;
	}
	return (-1);
}

void	push_to_a(t_intlist **a, t_intlist **b, t_oparr **oparr, int top_rank)
{
	int	index;
	int	size;

	size = ft_intlstsize(*b);
	index = find_index(*b, top_rank);
	if (index <= size / 2)
	{
		while ((*b)->rank != top_rank)
			op_rotate(NULL, b, oparr);
	}
	else
	{
		while ((*b)->rank != top_rank)
			op_reverse_rotate(NULL, b, oparr);
	}
	op_push_a(a, b, oparr);
}

void	algo_medium(t_intlist **a, t_intlist **b, t_oparr **oparr)
{
	int	nbr_amount;
	int	top_rank;

	if (!a || !b || !*a || *b)
		return ;
	nbr_amount = ft_intlstsize(*a);
	top_rank = nbr_amount - 1;
	assign_rank(*a, nbr_amount);
	assign_chunks(a, b, oparr);
	while (*b)
	{
		push_to_a(a, b, oparr, top_rank);
		top_rank--;
	}
}
