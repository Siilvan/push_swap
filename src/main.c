/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:52 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/15 14:09:31 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    int     *arr;
    int     bench;
    char    *mode;

    mode = "adaptive";
    bench = 0;
    arr = parse_input(argc, argv, &mode, &bench);
    ft_printf("%d\n", bench);
    ft_printf("%s\n", mode);
    for (int i = 0; i < 3; i++)
    {
        ft_printf("%d\n", arr[i]);
    }
    return(0);
}
