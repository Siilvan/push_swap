/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:43:11 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/19 17:31:17 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
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

int	ft_sqrt(int nb)
{
	int	res;

	res = 0;
	while (nb > (res * res))
		res++;
	return (res);
}
