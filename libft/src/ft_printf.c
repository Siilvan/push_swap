/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:01:03 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 11:02:57 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_rules(t_flag *flag)
{
	if (flag->precision < 0)
		flag->dot = 0;
	if (flag->plus && flag->space)
		flag->space = 0;
	if ((flag->dot || flag->minus) && flag->zero)
		flag->zero = 0;
	if (!(flag->to == 'x' || flag->to == 'X'))
		flag->hash = 0;
	if (!(flag->to == 'd' || flag->to == 'i' || flag->to == 'f'))
	{
		flag->space = 0;
		flag->plus = 0;
	}
	if (flag->to == 'p')
		flag->hash = 1;
	if (flag->to == 'c' || flag->to == 'p')
		flag->precision = 0;
	if (flag->to == 'c' || flag->to == 's' || flag->to == 'p')
		flag->zero = 0;
	if (flag->to == '%')
	{
		flag->width = 0;
		flag->minus = 0;
	}
}

int	ft_handle(va_list args, t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->to == 'c' || flag->to == '%')
		count = ft_putchar_printf(args, flag);
	if (flag->to == 's')
		count = ft_putstr_printf(args, flag);
	if (flag->to == 'p')
		count = ft_putptr_printf(args, flag);
	if (flag->to == 'd' || flag->to == 'i')
		count = ft_putnbr_printf(args, flag);
	if (flag->to == 'u')
		count = ft_putunbr_printf(args, flag);
	if (flag->to == 'x' || flag->to == 'X')
		count = ft_putunbr_printf(args, flag);
	if (flag->to == 'f')
		count = ft_putfloat_printf(args, flag);
	return (count);
}

int	ft_last_percent(int fd, const char *format)
{
	int	count;

	count = 1;
	if (!*format)
	{
		while (*format != '%')
			format--;
		count += ft_putstr_n(fd, (char *)format, ft_strlen(format) - 1);
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
				count += ft_format(1, (char *)format, args);
			while (*format && !ft_strchr(CONVERSIONS, *format))
				format++;
			if (!*format)
			{
				count += ft_last_percent(1, format);
				return (count);
			}
		}
		else
			count += ft_putchar_n(1, *format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

int	ft_fdprintf(int fd, const char *format, ...)
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
				count += ft_format(fd, (char *)format, args);
			while (*format && !ft_strchr(CONVERSIONS, *format))
				format++;
			if (!*format)
			{
				count += ft_last_percent(fd, format);
				return (count);
			}
		}
		else
			count += ft_putchar_n(fd, *format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
