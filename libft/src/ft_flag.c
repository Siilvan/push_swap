/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 09:50:25 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/15 09:49:08 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_flag	*ft_newformat(void)
{
	t_flag	*newflag;

	newflag = malloc(sizeof(t_flag));
	if (!newflag)
		return (NULL);
	newflag->dot = 0;
	newflag->zero = 0;
	newflag->plus = 0;
	newflag->star = 0;
	newflag->hash = 0;
	newflag->space = 0;
	newflag->minus = 0;
	newflag->width = 0;
	newflag->converto = 0;
	newflag->precision = 0;
	return (newflag);
}
