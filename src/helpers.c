/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:43:11 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 17:53:19 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(t_intlist *stack_a, t_intlist *stack_b, t_oparr *oparr)
{
	if (stack_a)
		ft_intlstclear(&stack_a);
	if (stack_b)
		ft_intlstclear(&stack_b);
	if (oparr)
		clear_oparr(&oparr);
	ft_putendl_fd("Error", 2);
	return (0);
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

int	ft_sqrt(int nb)
{
	int	res;

	res = 0;
	while (nb > (res * res))
		res++;
	return (res);
}
