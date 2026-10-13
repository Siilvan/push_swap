/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:40:41 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/05 15:13:09 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		slen;
	char	*ptr;

	slen = ft_strlen(s);
	ptr = (char *)s;
	while (slen >= 0)
	{
		if (ptr[slen] == (char)c)
			return (ptr + slen);
		slen--;
	}
	return (0);
}
