#include "ft_tester.h"
#include "libft.h"
#include "push_swap.h"
#include <time.h>

void	ft_print_buffer(char *name, char border, int length)
{
	int	b_len;
	int	tot_len;

	if (!border)
		b_len = 0;
	else
		b_len = ft_strlen(name);
	tot_len = length - b_len;
	ft_putchar_n(1, border, tot_len / 2);
	ft_putstr_fd(name, 1);
	ft_putchar_n(1, border, tot_len / 2);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
}

void	algo_to_test(char *algo, t_intlist *stack_a, t_intlist *stack_b)
{
	ft_print_buffer(algo, '=', 60);
	ft_printf("Before:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	if (!ft_strcmp(algo, "SIMPLE"))
		algo_simple(&stack_a, &stack_b);
	else if (!ft_strcmp(algo,  "MEDIUM"))
		algo_medium(&stack_a, &stack_b);
	else if (!ft_strcmp(algo, "COMPLEX"))
		algo_complex(&stack_a, &stack_b);
	ft_printf("After:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	ft_print_buffer("", '=', 60);
}

int	main()
{
	srand(time(0));
	t_intlist *stack_a = generate_random_stack(10);
	t_intlist *stack_b = NULL;
	algo_to_test("SIMPLE", stack_a, stack_b);
	stack_a = generate_random_stack(20);
	algo_to_test("MEDIUM", stack_a, stack_b);	
	stack_a = generate_random_stack(30);
	algo_to_test("COMPLEX", stack_a, stack_b);
}
