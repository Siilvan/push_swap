/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:06:18 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 09:15:14 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result(t_oparr *oparr)
{
	char	**op_names;
	int		i;
	t_oparr	*temp;

	i = 0;
	temp = oparr;
	op_names = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	if (op_names == NULL)
		return (NULL);
	while (i < oparr->n_op)
	{
		if (i == 2000)
		{
			temp = temp->next;
			i -= 2000;
			oparr->n_op -= 2000;
		}
		ft_printf("%s\n", op_names[temp->arr[i]]);
		i++;
	}
}

void	manage_result(t_oparr *oparr)
{
	if (oparr->n_op <= 50)
		print_result(oparr);
	else
	{
		ft_printf("%d\n", oparr->n_op - 1);
	}
}