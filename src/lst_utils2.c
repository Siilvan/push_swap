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

	while ((*lst))
	{
		temp1 = (*lst)->next;
		free((*lst));
		(*lst) = temp1;
	}
}
