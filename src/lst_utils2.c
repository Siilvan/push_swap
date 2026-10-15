/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 23:55:57 by ngero             #+#    #+#             */
/*   Updated: 2026/10/13 23:56:27 by ngero            ###   ########.fr       */
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
