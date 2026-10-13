/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 10:17:56 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/06 13:56:28 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		mark;
	size_t	i;
	int		count;

	i = 0;
	mark = 0;
	count = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c || s[i] == 0)
		{
			if (mark == 1)
				count++;
			mark = 0;
		}
		else
			mark = 1;
		i++;
	}
	return (count);
}

static char	**ft_free_me(char **ptrarray, int j)
{
	while (j > 0)
	{
		j--;
		free(ptrarray[j]);
	}
	free(ptrarray);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		next_c;
	char	**ptrarray;

	j = 0;
	ptrarray = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!ptrarray || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		next_c = 0;
		while (s[next_c] != c && s[next_c])
			next_c++;
		ptrarray[j] = ft_substr(s, 0, next_c);
		if (ptrarray[j] == NULL)
			return (ft_free_me(ptrarray, j));
		s += next_c;
		j++;
	}
	ptrarray[j] = 0;
	return (ptrarray);
}
