/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 09:26:18 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 16:57:51 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag_floats(t_flag *flag, char *base, long int n, int needed)
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
	else if (n < 0)
	{
		ft_putchar_n(flag->fd, '-', 1);
		n = -n;
	}
	if (flag->zero)
		ft_putchar_n(flag->fd, '0', flag->width - needed);
	if (n != 0 || !flag->dot || flag->precision > 0)
		ft_putnbr_base(flag->fd, n, base);
	if (flag->minus && !flag->zero)
		ft_putchar_n(flag->fd, ' ', flag->width - needed);
}

int	ft_putfloat_printf(va_list args, t_flag *flag)
{
	int		needed;
	int		i;
	double	frac;
	double	n;

	n = va_arg(args, double);
	if (!flag->dot)
		flag->precision = 6;
	needed = int_base(n, 10) + 1 + flag->precision;
	if (n >= 0 && (flag->plus || flag->space))
		needed += 1;
	ft_flag_floats(flag, "0123456789", n, needed);
	frac = n - (long int)n;
	i = 0;
	while (i < flag->precision)
	{
		frac *= 10;
		i++;
	}
	needed += ft_putchar_n(flag->fd, '.', 1);
	ft_putnbr_base(flag->fd, (unsigned long)frac, "0123456789");
	if (flag->width > needed)
		needed += flag->width - needed;
	return (needed);
}
