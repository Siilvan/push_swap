/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:45:27 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/02 18:36:13 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	long long	mult;
	void		*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	mult = nmemb * size;
	if (nmemb != mult / size)
		return (malloc(1));
	ptr = malloc(mult);
	if (ptr)
		ft_bzero(ptr, mult);
	return (ptr);
}
