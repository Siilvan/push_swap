/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:12:26 by ngero             #+#    #+#             */
/*   Updated: 2026/10/15 13:54:57 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap(t_intlist *l1, t_intlist *l2)
{
	int	tmp;

	if (!l1 || !l2)
		return ;
	tmp = l1->content;
	l1->content = l2->content;
	l2->content = tmp;
}

t_intlist	*ft_lstsecondtolast(t_intlist *lst)
{
	if (!lst || !lst->next)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_intlist	*ft_intlstlast(t_intlist *lst)
{
	t_intlist	*temp;

	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

void	ft_intlstadd_back(t_intlist **lst, t_intlist *new)
{
	t_intlist	*temp;

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

t_intlist	*ft_intlstnew(int content)
{
	t_intlist	*node;

	node = malloc(sizeof(t_intlist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
