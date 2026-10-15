/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:41:00 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/15 09:49:08 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_flagnbr(t_flag *flag, char *base, long int n, int needed)
{
	if (!flag->minus && !flag->zero)
		ft_putchar_n(' ', flag->width - needed);
	if (n >= 0)
	{
		if (flag->plus)
			ft_putchar_n('+', 1);
		else if (flag->space)
			ft_putchar_n(' ', 1);
	}
	else if (n < 0 && (flag->converto == 'd' || flag->converto == 'i'))
	{
		ft_putchar_n('-', 1);
		n = -n;
	}
	if (flag->converto == 'X' && flag->hash && n != 0)
		ft_putstr_n("0X", 2);
	else if (flag->hash && n != 0)
		ft_putstr_n("0x", 2);
	if (flag->zero)
		ft_putchar_n('0', flag->width - needed);
	ft_putchar_n('0', flag->precision - ft_digitbase_count(n, ft_strlen(base)));
	if (n != 0 || !flag->dot || flag->precision > 0)
		ft_putnbr_base(n, base);
	if (flag->minus && !flag->zero)
		ft_putchar_n(' ', flag->width - needed);
}

int	ft_digitbase_count(long n, int base_len)
{
	int	nlen;

	nlen = 0;
	if (n <= 0)
		nlen = 1;
	while (n != 0)
	{
		n /= base_len;
		nlen++;
	}
	return (nlen);
}

int	ft_putunbr_printf(va_list args, t_flag *flag)
{
	unsigned int	n;
	int				needed;
	char			*base;

	n = va_arg(args, unsigned int);
	if (flag->converto == 'x')
		base = "0123456789abcdef";
	else if (flag->converto == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	needed = ft_digitbase_count(n, ft_strlen(base));
	if (flag->dot && flag->precision > needed)
		needed += (flag->precision - needed);
	if (flag->hash && n != 0)
		needed += 2;
	if (!flag->precision && flag->dot && n == 0)
		needed = 0;
	ft_flagnbr(flag, base, n, needed);
	if (flag->width > needed)
		needed += flag->width - needed;
	return (needed);
}

int	ft_putnbr_printf(va_list args, t_flag *flag)
{
	int	n;
	int	needed;

	n = va_arg(args, int);
	needed = ft_digitbase_count(n, 10);
	if (flag->dot && flag->precision > needed)
	{
		needed += (flag->precision - needed);
		if (n < 0)
			needed++;
	}
	if (!flag->precision && flag->dot && n == 0)
		needed = 0;
	if (n >= 0 && (flag->plus || flag->space))
		needed += 1;
	ft_flagnbr(flag, "0123456789", n, needed);
	if (flag->width > needed)
		needed += flag->width - needed;
	return (needed);
}
