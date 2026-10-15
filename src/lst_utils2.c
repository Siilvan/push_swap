/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 23:55:57 by ngero             #+#    #+#             */
/*   Updated: 2026/10/15 13:52:18 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intlstclear(t_intlist **lst)
{
	t_intlist	*temp1;

	if (!lst)
		return ;
	while (*lst)
	{
		temp1 = (*lst)->next;
		free(*lst);
		(*lst) = temp1;
	}
	*lst = 0;
}

int	ft_intlstsize(t_intlist *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next; 
		i++;
	}
	return (i);
}
