/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:39:47 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/02 17:42:45 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*dup;

	slen = ft_strlen(s) + 1;
	dup = malloc(slen * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, slen);
	return (dup);
}
