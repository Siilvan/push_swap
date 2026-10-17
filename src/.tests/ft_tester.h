#ifndef FT_TESTER_H
# define FT_TESTER_H
# define COLRED "\033[31m"
# define COLGREEN "\033[32m"
# define COLBLUE "\033[34m"
# define COLCLEAR "\033[0m"
# define COUNT_ARGS_IMPL(a, b, c, d, e, f, g, h, i, j, N, ...) N
# define ARGC(...) COUNT_ARGS_IMPL(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
# define TEST_HEADER(name) \
	do { \
		ft_printf("\n%s====%s====%s\n", COLBLUE, name, COLCLEAR); \
	} while (0)
# define PRINT_ERR(...) \
	do {\
		ft_printf("%s==========[ERROR]=========%s\n", COLRED, COLCLEAR); \
		ft_printf("%stest: %s%s\n", COLBLUE, name, COLCLEAR); \
		__VA_ARGS__ \
		ft_printf("%s==========================%s\n", COLRED, COLCLEAR); \
	} while (0);
# define PRINT_SUCCESS() \
	do { \
		ft_printf("%s%s%s : OK%s\n", COLBLUE, name, COLGREEN, COLCLEAR); \
	} while (0)
#include "push_swap.h"
#include <stdlib.h>

t_intlist	*generate_random_stack(size_t size);
int			test_stack_disorder(t_intlist *stack, int expected, const char *name);
int			test_stack_order(t_intlist *stack, const char *name);
int			test_full(int argc, const char *args, int expected, const char *name);
int			test_user_input(char **av, int ac, t_userinput *expected, const char *name);
void		print_stack(t_intlist *stack, const char *stack_name);
int			userinput_cmp(t_userinput *ui1, t_userinput *ui2);
void		print_userinput(t_userinput *ui, const char *ui_name);

#endif
