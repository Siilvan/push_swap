/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:01:13 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/10 15:35:26 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		star;
	int		width;
	int		precision;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	char	converto;
}	t_flag;

# define CONVERSIONS	"cspdiuxX%"

int		ft_putchar_n(char c, int n);
int		ft_putstr_n(char *str, int len);
int		ft_digitbase_count(long n, int base_len);
int		ft_format(char *str, va_list args);
int		ft_printf(const char *format, ...);
int		ft_handle(va_list args, t_flag *flag);
int		ft_putstr_printf(va_list args, t_flag *flag);
int		ft_putptr_printf(va_list args, t_flag *flag);
int		ft_putnbr_printf(va_list args, t_flag *flag);
int		ft_putunbr_printf(va_list args, t_flag *flag);
int		ft_putchar_printf(va_list args, t_flag *flag);
void	ft_check_rules(t_flag *flag);
void	ft_putnbr_base(unsigned long int n, char *base);
void	ft_flagnbr(t_flag *flag, char *base, long int n, int needed);
t_flag	*ft_newformat(void);

#endif