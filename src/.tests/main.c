#include "ft_tester.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main()
{
	srand(time(0));
	// for (int i = 0; i < 10; i++)
	// {
	// 	t_intlist *stack = generate_random_stack(rand() % 15);
	// 	print_stack(stack, "Stack");
	// 	ft_intlstclear(&stack);
	// }
	t_intlist *stack_a = generate_random_stack(7);
	t_intlist *stack_b = NULL;
	printf("Before:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	algo_simple(&stack_a, &stack_b);

	printf("After:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
}
