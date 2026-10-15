/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:57:43 by ngero             #+#    #+#             */
/*   Updated: 2026/10/15 13:54:42 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_intlist *stack)
{
	double			mistakes;
	double			total_pairs;
	t_intlist		*seeker;

	mistakes = 0;
	total_pairs = 0;
	seeker = stack;
	while (stack)
	{
		seeker = stack->next;
		while (seeker)
		{
			total_pairs++;
			if (stack->content > seeker->content)
				mistakes++;
			seeker = seeker->next;
		}
		stack = stack->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}
