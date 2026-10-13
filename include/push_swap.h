/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:45 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/13 13:32:12 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./ft_printf/ft_printf.h"


// Not sure if this is the proper way to do it. Now when running the actual algorithm we'll have to
// do t_info->nbrs[i], might be an issue with norm line length.
// Maybe make a seperate struct for the stacks (linked list????).
typedef struct s_info
{
	int		bench;
	int		*nbrs;
	char	*mode;
}	t_info;
// How to handle benchmark operation count??? first thought seperate struct, but then need an extra parameter
// and count everywhere which is ugly and takes a lot of lines. 
// Maybe make a seperate function that only does the printing?
// So simple function that takes a string, prints it and adds it to the count in bench struct if bench flag enabled.
// But idk im probs overlooking a very simple solution.
// and i gave up on nvim ill follow a proper tutorial sometime.

int		parse_input(int argc, char *args[], t_info *info);
void	i_want_to_be_free(t_info *info);
t_info	*new_info(void);

#endif