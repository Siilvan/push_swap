/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:43:11 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/15 13:54:48 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	error_exit()
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
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
