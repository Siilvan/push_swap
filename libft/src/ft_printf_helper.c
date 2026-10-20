/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:06:40 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 10:43:20 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_n(int fd, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, &c, 1);
		i++;
	}
	return (n);
}

int	ft_putstr_n(int fd, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	return (len);
}

void	ft_putnbr_base(int fd, unsigned long int n, char *base)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(fd, n / base_len, base);
		ft_putnbr_base(fd, n % base_len, base);
	}
	if (n < base_len)
	{
		ft_putchar_fd(base[n], fd);
	}
}
