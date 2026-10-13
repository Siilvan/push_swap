/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:36:20 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/05 11:40:59 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*sjoin;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	sjoin = malloc(size);
	if (sjoin == NULL)
		return (NULL);
	sjoin[0] = 0;
	ft_strlcat(sjoin, s1, size);
	ft_strlcat(sjoin, s2, size);
	return (sjoin);
}
