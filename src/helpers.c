/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:43:11 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/14 00:34:57 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	i_want_to_be_free(t_info *info)
{
	int	i;

	i = 0;
	free(info->nbrs);
	free(info->mode);
	free(info);
}

t_intlist	*get_stack_from_arr(int *arr, size_t size)
{
	size_t		i;
	t_intlist	*lst;
	t_intlist	*new;

	i = 0;
	lst = 0;
	while (i < size)
	{
		new = ft_intlstnew(arr[i]);
		if (!new)
		{
			ft_intlstclear(&lst);
			return (0);
		}
		ft_intlstadd_back(&lst, new);
		i++;
	}
	return (lst);
}
