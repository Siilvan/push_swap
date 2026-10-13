/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:47:51 by sgroenve          #+#    #+#             */
/*   Updated: 2026/09/29 17:03:24 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (size + ft_strlen(src));
	size = size - dstlen;
	i = 0;
	while (src[i] && (i < (size - 1)))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	return (dstlen + ft_strlen(src));
}
