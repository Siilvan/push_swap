#include "ft_tester.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <time.h>

int	main()
{
	srand(time(0));
	t_intlist *stack_a = generate_random_stack(10);
	t_intlist *stack_b = NULL;
	ft_printf("Before:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// op_reverse_rotate(&stack_a, NULL);
	algo_simple(&stack_a, &stack_b);

	ft_printf("After:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
}
