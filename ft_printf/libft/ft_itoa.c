/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:30:22 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/05 14:28:42 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_digit_count(int n)
{
	int	nlen;

	nlen = 0;
	if (n <= 0)
		nlen = 1;
	while (n != 0)
	{
		n /= 10;
		nlen++;
	}
	return (nlen);
}

char	*ft_itoa(int n)
{
	char		*strn;
	long int	nbr;
	int			nlen;
	int			flag;

	flag = 0;
	nlen = ft_digit_count(n);
	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		flag = 1;
	}
	strn = malloc(nlen + 1);
	if (!strn)
		return (NULL);
	strn[nlen--] = 0;
	while (nlen >= 0)
	{
		strn[nlen--] = 48 + (nbr % 10);
		nbr /= 10;
	}
	if (flag)
		strn[0] = '-';
	return (strn);
}
