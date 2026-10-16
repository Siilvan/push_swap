/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:41:00 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 11:04:31 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_flagnbr(t_flag *flag, char *base, long int n, int needed)
{
	if (!flag->minus && !flag->zero)
		ft_putchar_n(flag->fd, ' ', flag->width - needed);
	if (n >= 0)
	{
		if (flag->plus)
			ft_putchar_n(flag->fd, '+', 1);
		else if (flag->space)
			ft_putchar_n(flag->fd, ' ', 1);
	}
	else if (n < 0 && (flag->to == 'd' || flag->to == 'i'))
	{
		ft_putchar_n(flag->fd, '-', 1);
		n = -n;
	}
	if (flag->to == 'X' && flag->hash && n != 0)
		ft_putstr_n(flag->fd, "0X", 2);
	else if (flag->hash && n != 0)
		ft_putstr_n(flag->fd, "0x", 2);
	if (flag->zero)
		ft_putchar_n(flag->fd, '0', flag->width - needed);
	ft_putchar_n(flag->fd, '0', flag->precision - int_base(n, ft_strlen(base)));
	if (n != 0 || !flag->dot || flag->precision > 0)
		ft_putnbr_base(flag->fd, n, base);
	if (flag->minus && !flag->zero)
		ft_putchar_n(flag->fd, ' ', flag->width - needed);
}

int	int_base(long n, int base_len)
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
	if (flag->to == 'x')
		base = "0123456789abcdef";
	else if (flag->to == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	needed = int_base(n, ft_strlen(base));
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
	needed = int_base(n, 10);
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
