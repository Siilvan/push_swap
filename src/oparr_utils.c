/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oparr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:09:23 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/15 17:48:16 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oparr	*oparrnew(void)
{
	t_oparr	*new;

	new = malloc(sizeof(t_oparr));
	if (!new)
		return (NULL);
	new->n_op = 0;
	new->next = NULL;
}

void	clear_oparr(t_oparr **start)
{
	t_oparr *tmp;

	if (!start)
		return;
	while (tmp != NULL)
	{
		tmp = (*start)->next;
		free(*start);
		(*start) = tmp;
	}
	*start = NULL;
}

int	ft_add_op(t_oparr *node, int op)
{
	t_oparr	*new;

	new = NULL;
	if ((node->n_op % 2000) == 0 && node->n_op != 0)
	{
		new = oparrnew();
		if (!new)
			return (-1);
		new->n_op = node->n_op;
		ft_lstadd_back(&node, new);
	}
	if ((node->n_op / 2000) > 0)
		new = ft_lstlast(node);
	new->arr[(node->n_op % 100)] = op;
	new->n_op += 1;
	return (0);
}
