/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:06:19 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 11:36:05 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define CONVERSIONS	"fcspdiuxX%"

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
	int		fd;
	char	to;
}	t_flag;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char	*nptr);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *str, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void	*content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(const char *format, ...);
int		ft_fdprintf(int fd, const char *format, ...);
int		ft_putchar_n(int fd, char c, int n);
int		ft_putstr_n(int fd, char *str, int len);
int		int_base(long n, int base_len);
int		ft_format(int fd, char *str, va_list args);
int		ft_handle(va_list args, t_flag *flag);
int		ft_putstr_printf(va_list args, t_flag *flag);
int		ft_putptr_printf(va_list args, t_flag *flag);
int		ft_putnbr_printf(va_list args, t_flag *flag);
int		ft_putunbr_printf(va_list args, t_flag *flag);
int		ft_putfloat_printf(va_list args, t_flag *flag);
int		ft_putchar_printf(va_list args, t_flag *flag);
void	ft_check_rules(t_flag *flag);
void	ft_putnbr_base(int fd, unsigned long int n, char *base);
void	ft_flagnbr(t_flag *flag, char *base, long int n, int needed);
t_flag	*ft_newformat(void);

#endif