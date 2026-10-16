#ifndef FT_TESTER_H
# define FT_TESTER_H
# define COLRED "\033[31m"
# define COLGREEN "\033[32m"
# define COLCLEAR "\033[0m"
# define PRINT_ERR(...) \
	do { \
		printf("%s==\t[ERROR]\t==%s\n", COLRED, COLCLEAR); \
		printf(__VA_ARGS__); \
		printf("==================="); \
	} while (0)

#include "push_swap.h"
#include <stdlib.h>

t_intlist	*generate_random_stack(size_t size);
int			test_stack_disorder(t_intlist *stack, int expected);
int			test_stack_order(t_intlist *stack);
void		print_stack(t_intlist *stack, const char *stack_name);

#endif
