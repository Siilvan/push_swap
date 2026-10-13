/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 09:22:09 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/05 17:39:29 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		begin;
	int		end;
	int		len;
	char	*trimmedstr;

	begin = 0;
	end = ft_strlen(s1) - 1;
	while (begin <= end && ft_strchr(set, s1[begin]))
		begin++;
	while (end >= begin && ft_strchr(set, s1[end]))
		end--;
	len = end - begin + 2;
	trimmedstr = malloc(len);
	if (!trimmedstr)
		return (NULL);
	ft_strlcpy(trimmedstr, s1 + begin, len);
	return (trimmedstr);
}
