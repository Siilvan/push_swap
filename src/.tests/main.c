#include "ft_tester.h"
#include "../../include/push_swap.h"
#include <stdlib.h>
#include <time.h>

int	main()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		t_intlist *stack = generate_random_stack(rand() % 15);
		print_stack(stack, "Stack");
		ft_intlstclear(&stack);
	}
}
