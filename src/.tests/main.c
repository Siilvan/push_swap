#include "ft_tester.h"
#include "push_swap.h"
#include <time.h>

void	sorting__test()
{
	int	i;


	TEST_HEADER("SIMPLE SORTING TESTS");
	i = 0;
	while (i < 10)
	{
		t_intlist	*stack_a = generate_random_stack(rand() % 500);
		t_intlist	*stack_b = NULL;
		t_oparr		*op_arr;

		op_arr = oparrnew();
		algo_simple(&stack_a, &stack_b, &op_arr);
		test_stack_order(stack_a, "Simple algorithm test");
		ft_cleanup(&stack_a, &stack_b, &op_arr, NULL);
		i++;
	}
	TEST_HEADER("MEDIUM SORTING TESTS");
	i = 0;
	while (i < 10)
	{
		t_intlist *stack_a = generate_random_stack(rand() % 500);
		t_intlist *stack_b = NULL;
		t_oparr		*op_arr;

		op_arr = oparrnew();
		algo_medium(&stack_a, &stack_b, &op_arr);
		test_stack_order(stack_a, "Medium algorithm tests");
		ft_cleanup(&stack_a, &stack_b, &op_arr, NULL);
		i++;
	}
	TEST_HEADER("COMPLEX SORTING TESTS");
	i = 0;
	while (i < 10)
	{
		t_intlist *stack_a = generate_random_stack(rand() % 500);
		t_intlist *stack_b = NULL;
		t_oparr		*op_arr;

		op_arr = oparrnew();
		algo_complex(&stack_a, &stack_b, &op_arr);
		test_stack_order(stack_a, "Complex algorithm tests");
		ft_cleanup(&stack_a, &stack_b, &op_arr, NULL);
		i++;
	}
}

void	user_input__test()
{
	TEST_HEADER("USER INPUT TESTS");
	test_user_input(
			(char*[]){"file", "0", "-6", "-314", "-109"},
			5,
			&(t_userinput){0, "adaptive", (int[]){0, -6, -314, -109}, 4},
			"no bench, no spec single value array"
			);
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
			(char*[]){"file", "10", "2", "3", "10", "\t"},
			6,
			NULL,
			"Invalid input: duplicates"
			);
	test_user_input(
			(char*[]){"file", "--+10", "+++   20"},
			3,
			NULL,
			"Invalid input: invalid atoi call"
			);
	test_user_input(
			(char*[]){"file"},
			1,
			NULL,
			"Invalid input: no input"
			);
	test_user_input(
			(char*[]){"file", "--simple"},
			2,
			NULL,
			"Invalid input: algo spec, no array"
			);
}

void	full__test()
{
	TEST_HEADER("COMPLETE TESTS");
	test_full(
			12,
			"./file --adaptive 3 2 1 4 5 6 -5 32 -1 -2",
			1,
			"Adaptive valid input"
			);
	test_full(
			3,
			"./file --complex 0",
			1,
			"Complex, single number stack"
			);
	test_full(
			5,
			"./file --bench --complex 0 -1",
			1,
			"Complex, double number stack"
			);
	test_full(
			5,
			"./file 0 -1 -9999 -9",
			1,
			"No algo spec, small negative stack"
			);
	test_full(
			1,
			"./file",
			0,
			"No input"
			);
	test_full(
			2,
			"./file --simple",
			0,
			"Algo spec, no array"
			);
}

int	main()
{
	srand(time(0));
	user_input__test();
	sorting__test();
	full__test();
}
