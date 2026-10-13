/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:01:03 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/10 14:25:18 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_check_rules(t_flag *flag)
{
	if (flag->precision < 0)
		flag->dot = 0;
	if (flag->plus && flag->space)
		flag->space = 0;
	if ((flag->dot || flag->minus) && flag->zero)
		flag->zero = 0;
	if (!(flag->converto == 'x' || flag->converto == 'X'))
		flag->hash = 0;
	if (!(flag->converto == 'd' || flag->converto == 'i'))
	{
		flag->space = 0;
		flag->plus = 0;
	}
	if (flag->converto == 'p')
		flag->hash = 1;
	if (flag->converto == 'c' || flag->converto == 'p')
		flag->precision = 0;
	if (flag->converto == 'c' || flag->converto == 's' || flag->converto == 'p')
		flag->zero = 0;
	if (flag->converto == '%')
	{
		flag->width = 0;
		flag->minus = 0;
	}
}

int	ft_handle(va_list args, t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->converto == 'c' || flag->converto == '%')
		count = ft_putchar_printf(args, flag);
	if (flag->converto == 's')
		count = ft_putstr_printf(args, flag);
	if (flag->converto == 'p')
		count = ft_putptr_printf(args, flag);
	if (flag->converto == 'd' || flag->converto == 'i')
		count = ft_putnbr_printf(args, flag);
	if (flag->converto == 'u')
		count = ft_putunbr_printf(args, flag);
	if (flag->converto == 'x' || flag->converto == 'X')
		count = ft_putunbr_printf(args, flag);
	return (count);
}

int	ft_last_percent(const char *format)
{
	int	count;

	count = 1;
	if (!*format)
	{
		while (*format != '%')
			format--;
		count += ft_putstr_n((char *)format, ft_strlen(format) - 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format))
				count += ft_format((char *)format, args);
			while (*format && !ft_strchr(CONVERSIONS, *format))
				format++;
			if (!*format)
			{
				count += ft_last_percent(format);
				return (count);
			}
		}
		else
			count += ft_putchar_n(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
