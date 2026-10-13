/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:43:11 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/13 13:40:11 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	i_want_to_be_free(t_info *info)
{
	int	i;

	i = 0;
	free(info->nbrs);
	free(info->mode);
	free(info);
}
