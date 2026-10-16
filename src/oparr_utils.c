/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oparr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:09:23 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 14:44:15 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_oparr_back(t_oparr **lst, t_oparr *new)
{
	t_oparr	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

t_oparr	*ft_oparrlast(t_oparr *lst)
{
	t_oparr	*temp;

	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

t_oparr	*oparrnew(void)
{
	t_oparr	*new;

	new = malloc(sizeof(t_oparr));
	if (!new)
		return (NULL);
	new->n_op = 0;
	new->next = NULL;
	return (new);
}

void	clear_oparr(t_oparr **start)
{
	t_oparr *tmp;

	while (*start != NULL)
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
		ft_oparr_back(&node, new);
	}
	if ((node->n_op / 2000) > 0)
		new = ft_oparrlast(node);
	new->arr[(node->n_op % 100)] = op;
	new->n_op += 1;
	return (0);
}
