/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:55:54 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 18:14:49 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_cpyarr(int *cpy, int n)
{
	int	i;
	int	j;
	int	save;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (cpy[j] > cpy[j + 1])
			{
				save = cpy[j];
				cpy[j] = cpy[j + 1];
				cpy[j + 1] = save;
			}
			j++;
		}
		i++;
	}
}
int	*create_cpyarr(t_intlist *stack_a, int n)
{
	int			i;
	int			*cpy;
	t_intlist	*temp;

	temp = stack_a;
	i = 0;
	cpy = malloc(sizeof(int) * n);
	if (!cpy)
		return (NULL);
	while (i < n)
	{
		cpy[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return(cpy);
}
void	assign_rank(t_intlist *stack_a, int n)
{
	int			i;
	int			*cpy;
	t_intlist	*temp;

	cpy = create_cpyarr(stack_a, n);
	if (!cpy)
		return;
	sort_cpyarr(cpy, n);
	temp = stack_a;
	while(temp)
	{
		i = 0;
		while (i < n)
		{
			if (cpy[i] == temp->content)
			{
				temp->rank = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}
	free(cpy);
}

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
