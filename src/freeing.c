/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:30:59 by ngero             #+#    #+#             */
/*   Updated: 2026/10/19 17:50:03 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cleanup(t_intlist **stack_a, t_intlist **stack_b, t_oparr **oparr,
		t_userinput **uinput)
{
	if (stack_a)
		ft_intlstclear(stack_a);
	if (stack_b)
		ft_intlstclear(stack_b);
	if (oparr)
		clear_oparr(oparr);
	if (uinput)
		free_userinput(uinput);
}

int	error_exit(t_intlist **stack_a, t_intlist **stack_b, t_oparr **oparr,
		t_userinput **uinput)
{
	ft_cleanup(stack_a, stack_b, oparr, uinput);
	ft_putendl_fd("Error", 2);
	return (0);
}
    

void	ft_freesplit(char **split)
{
	char	**seeker;

	if (!split)
		return ;
	seeker = split;
	while (*seeker)
	{
		free(*seeker);
		seeker++;
	}
	free(split);
}

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
