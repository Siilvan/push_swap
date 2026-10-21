/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oparr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:09:23 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/21 15:43:51 by ngero            ###   ########.fr       */
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

	if (!lst)
		return (0);
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
	int		i;

	new = malloc(sizeof(t_oparr));
	if (!new)
		return (NULL);
	i = 0;
	while (i < 2000)
	{
		new->arr[i] = -1;
		i++;
	}
	new->n_op = 0;
	new->next = NULL;
	return (new);
}

void	clear_oparr(t_oparr **start)
{
	t_oparr	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		free(*start);
		(*start) = tmp;
	}
	*start = NULL;
}

int	ft_add_op(t_oparr **node, int op)
{
	t_oparr	*new;
	t_oparr	*last;

	if (!node || !*node)
		return (0);
	last = ft_oparrlast(*node);
	new = NULL;
	if (last->n_op == 2000)
	{
		new = oparrnew();
		if (!new)
			sort_stack(0, NULL);
		ft_oparr_back(node, new);
		last = new;
	}
	last->arr[last->n_op] = op;
	last->n_op += 1;
	return (1);
}
