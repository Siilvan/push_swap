/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:52 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/13 15:53:05 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_info	*info;

    info = new_info();
	if (!info)
		return (1);
    parse_input(argc, argv, info);
    ft_printf("%d\n", info->bench);
    ft_printf("%s\n", info->mode);
    // for (int i = 2; i < argc; i++)
    // {
    //     ft_printf("%d\n", info->nbrs);
    // }
   //i_want_to_be_free(info);
    return(0);
}
