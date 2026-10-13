/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:57:43 by ngero             #+#    #+#             */
/*   Updated: 2026/10/14 00:48:02 by ngero            ###   ########.fr       */
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
