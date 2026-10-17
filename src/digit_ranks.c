/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_ranks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:17:57 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 13:11:09 by sgroenve         ###   ########.fr       */
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
	return (cpy);
}

void	assign_rank(t_intlist *stack_a, int n)
{
	int			i;
	int			*cpy;
	t_intlist	*temp;

	cpy = create_cpyarr(stack_a, n);
	if (!cpy)
		return ;
	sort_cpyarr(cpy, n);
	temp = stack_a;
	while (temp)
	{
		i = 0;
		while (i < n)
		{
			if (cpy[i] == temp->content)
			{
				temp->rank = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
	free(cpy);
}
