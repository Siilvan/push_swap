/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:06:18 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/19 17:36:37 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_result(t_oparr *oparr)
{
	char	**op_names;
	int		i;
	int		val;
	t_oparr	*temp;

	i = 0;
	op_names = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	if (op_names == NULL)
		return (-1);
	temp = oparr;
	while (temp)
	{
		i = 0;
		while (i < temp->n_op)
		{
			val = temp->arr[i];
			if (val >= 0 && val <= 10)
				ft_printf("%s\n", op_names[val]);
			i++;
		}
		temp = temp->next;
	}
	ft_freesplit(op_names);
	return (1);
}

void	manage_result(t_oparr **oparr, int testing)
{
	if (testing)
		return ;
	if ((*oparr)->n_op > 0)
		print_result(*oparr);
}
