/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:19:37 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/10 14:38:01 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_count(unsigned long n)
{
	int	nlen;

	nlen = 0;
	if (n <= 0)
		nlen = 1;
	while (n != 0)
	{
		n /= 16;
		nlen++;
	}
	return (nlen);
}

int	ft_putptr_printf(va_list args, t_flag *flag)
{
	unsigned long	n;
	int				needed;

	n = va_arg(args, unsigned long);
	if (!n)
	{
		if (flag->width > 5 && !flag->minus)
			ft_putchar_n(' ', flag->width - 5);
		ft_putstr_n("(nil)", 5);
		if (flag->width > 5 && flag->minus)
			ft_putchar_n(' ', flag->width - 5);
		if (flag->width > 5)
			return (flag->width);
		else
			return (5);
	}
	needed = ft_ptr_count(n);
	if (flag->dot && flag->precision > needed)
		needed += (flag->precision - needed);
	needed += 2;
	ft_flagnbr(flag, "0123456789abcdef", n, needed);
	if (flag->width > needed)
		needed += flag->width - needed;
	return (needed);
}
