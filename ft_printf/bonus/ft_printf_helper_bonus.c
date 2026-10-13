/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:06:40 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/10 12:27:38 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_n(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (n);
}

int	ft_putstr_n(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (len);
}

void	ft_putnbr_base(unsigned long int n, char *base)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
		ft_putnbr_base(n % base_len, base);
	}
	if (n < base_len)
	{
		ft_putchar_fd(base[n], 1);
	}
}
