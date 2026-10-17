#include "ft_tester.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <time.h>

void	sorting__test()
{
	int	i;

	TEST_HEADER("SORTING TESTS");

	i = 0;
	while (i < 10)
	{
		t_intlist *stack_a = generate_random_stack(rand() % 100);
		t_intlist *stack_b = NULL;
		// algo_simple(&stack_a, &stack_b);
		test_stack_order(stack_a, "Simple algorithm test");
		i++;
	}
	// i = 0;
	// while (i < 10)
	// {
	// 	t_intlist *stack_a = generate_random_stack(rand() % 100);
	// 	t_intlist *stack_b = NULL;
	// 	algo_medium(&stack_a, &stack_b);
	// 	test_stack_order(stack_a, "Medium algorithm tests");
	// }
}

void	user_input__test()
{
	TEST_HEADER("USER INPUT TESTS");
	test_user_input(
			(char*[]){"file", "--simple", "3", "6", "2", "-109"},
			6,
			&(t_userinput){0, "simple", (int[]){3, 6, 2, -109}, 4},
			"no bench, simple and valid array"
			);
	test_user_input(
			(char*[]){"file", "--medium", "3", "6", "2", "-109"},
			6,
			&(t_userinput){0, "medium", (int[]){3, 6, 2, -109}, 4},
			"no bench, medium and valid array"
			);
	test_user_input(
			(char*[]){"file", "--complex", "3", "6", "2", "-109"},
			6,
			&(t_userinput){0, "complex", (int[]){3, 6, 2, -109}, 4},
			"no bench, complex and valid array"
			);
	test_user_input(
			(char*[]){"file", "--adaptive", "3", "6", "2", "-109"},
			6,
			&(t_userinput){0, "adaptive", (int[]){3, 6, 2, -109}, 4},
			"no bench adaptive and valid array"
			);
	test_user_input(
			(char*[]){"file", "--bench", "--simple", "3", "6", "2", "1"},
			7,
			&(t_userinput){1, "simple", (int[]){3, 6, 2, 1}, 4},
			"bench, simple and valid array"
			);
	test_user_input(
			(char*[]){"file", "--bench", "--medium", "3", "6", "2", "1"},
			7,
			&(t_userinput){1, "medium", (int[]){3, 6, 2, 1}, 4},
			"bench, medium and valid array"
			);
	test_user_input(
			(char*[]){"file", "--bench", "--adaptive", "3", "6", "2", "1"},
			7,
			&(t_userinput){1, "adaptive", (int[]){3, 6, 2, 1}, 4},
			"bench, adaptive and valid array"
			);
	test_user_input(
			(char*[]){"file", "--bench", "--complex", "3", "6", "2", "1"},
			7,
			&(t_userinput){1, "complex", (int[]){3, 6, 2, 1}, 4},
			"bench, complex and valid array"
			);
	test_user_input(
			(char*[]){"file", "3", "6", "2", "-109"},
			5,
			&(t_userinput){0, "adaptive", (int[]){3, 6, 2, -109}, 4},
			"no bench, no algo spec and valid array"
			);
	test_user_input(
			(char*[]){"file", "3", "6", "2", "-109"},
			5,
			&(t_userinput){0, "adaptive", (int[]){3, 6, 2, -109}, 4},
			"bench, no algo spec and valid array"
			);
	test_user_input(
			(char*[]){"file"},
			1,
			NULL,
			"Invalid input: not enough args"
			);
	test_user_input(
			(char*[]){"file", "Eat shit."},
			2,
			NULL,
			"Invalid input: stupid args"
			);
	test_user_input(
			(char*[]){"file", "10", "3a", "b2", "WW", "\t"},
			6,
			NULL,
			"Invalid input: letters in array"
			);
	test_user_input(
			(char*[]){"file", "--+10", "+++   20"},
			3,
			NULL,
			"Invalid input: invalid atoi call"
			);
}

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

// void	algo_to_test(char *algo, t_intlist *stack_a, t_intlist *stack_b)
// {
// 	ft_print_buffer(algo, '=', 60);
// 	ft_printf("Before:\n");
// 	print_stack(stack_a, "A");
// 	print_stack(stack_b, "B");
// 	if (!ft_strcmp(algo, "SIMPLE"))
// 		algo_simple(&stack_a, &stack_b);
// 	else if (!ft_strcmp(algo,  "MEDIUM"))
// 		algo_medium(&stack_a, &stack_b);
// 	else if (!ft_strcmp(algo, "COMPLEX"))
// 		algo_complex(&stack_a, &stack_b);
// 	ft_printf("After:\n");
// 	print_stack(stack_a, "A");
// 	print_stack(stack_b, "B");
// 	ft_print_buffer("", '=', 60);
// }

int	main()
{
	srand(time(0));
	user_input__test();
	sorting__test();
	// t_intlist *stack_a = generate_random_stack(10);
	// t_intlist *stack_b = NULL;
	// algo_to_test("SIMPLE", stack_a, stack_b);
	// stack_a = generate_random_stack(20);
	// algo_to_test("MEDIUM", stack_a, stack_b);	
	// stack_a = generate_random_stack(30);
	// algo_to_test("COMPLEX", stack_a, stack_b);
}
