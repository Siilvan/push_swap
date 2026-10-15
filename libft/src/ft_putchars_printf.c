/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:10:10 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/15 09:49:08 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar_printf(va_list args, t_flag *flag)
{
	char	c;
	int		size;

	size = 1;
	if (flag->converto == 'c')
		c = va_arg(args, int);
	else
		c = '%';
	if (!flag->minus)
		ft_putchar_n(' ', flag->width - 1);
	ft_putchar_fd(c, 1);
	if (flag->minus)
		ft_putchar_n(' ', flag->width - 1);
	if (flag->width)
		size = flag->width;
	return (size);
}

int	ft_putstr_printf(va_list args, t_flag *flag)
{
	int		strlen;
	char	*str;
	int		size;

	str = va_arg(args, char *);
	if (!str && flag->dot && flag->precision < 6)
		str = "";
	else if (!str)
	{
		str = "(null)";
	}
	strlen = ft_strlen(str);
	if (flag->precision >= 0 && flag->dot && flag->precision < strlen)
		strlen = flag->precision;
	if (!flag->minus)
		ft_putchar_n(' ', flag->width - strlen);
	ft_putstr_n(str, strlen);
	if (flag->minus)
		ft_putchar_n(' ', flag->width - strlen);
	if (strlen < flag->width)
		size = flag->width;
	else
		size = strlen;
	return (size);
}
