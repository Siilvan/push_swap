/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:52:37 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 10:57:45 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flags(char *str, t_flag *flag)
{
	while (*str != '.' && !ft_strchr(CONVERSIONS, *str))
	{
		if (*str == ' ')
			flag->space = 1;
		if (*str == '#')
			flag->hash = 1;
		if (*str == '+')
			flag->plus = 1;
		str++;
	}
}

void	ft_findwidth(char *str, va_list args, t_flag *flag)
{
	int	is_set;

	is_set = 0;
	while (*str != '.' && !ft_strchr(CONVERSIONS, *str))
	{
		if (*str == '-')
			flag->minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			flag->zero = 1;
		if (!is_set && ((*str >= '0' && *str <= '9') || *str == '*'))
		{
			if (*str == '*')
				flag->width = va_arg(args, int);
			else
				flag->width = ft_atoi(str);
			is_set = 1;
		}
		str++;
	}
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
}

void	ft_precision(char *str, va_list args, t_flag *flag)
{
	int	is_set;

	is_set = 0;
	flag->dot = 1;
	while (!ft_strchr(CONVERSIONS, *str) && !is_set)
	{
		if (ft_isdigit(*str) || *str == '*')
		{
			if (*str == '*')
				flag->precision = va_arg(args, int);
			else
				flag->precision = ft_atoi(str);
			is_set = 1;
		}
		str++;
	}
}

int	ft_format(int fd, char *str, va_list args)
{
	t_flag	*flags;
	int		count;

	flags = ft_newformat();
	if (flags == NULL)
		return (0);
	flags->fd = fd;
	ft_findwidth(str, args, flags);
	ft_flags(str, flags);
	while (!ft_strchr(CONVERSIONS, *str) && *str != '.')
		str++;
	if (flags->to == 0 && *str == '.')
	{
		ft_precision(str, args, flags);
		while (!ft_strchr(CONVERSIONS, *str))
			str++;
	}
	flags->to = *str;
	ft_check_rules(flags);
	count = ft_handle(args, flags);
	free(flags);
	return (count);
}
