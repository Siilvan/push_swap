#include "ft_tester.h"
#include "libft.h"
#include "push_swap.h"
#include <stddef.h>

void	print_stack(t_intlist *stack, const char *stack_name)
{
	double	disorder;

	disorder = compute_disorder(stack);
	if (!stack)
		return (ft_printf("%s NULL_STACK\n", stack_name), (void)0);
	ft_printf("%s {", stack_name);
	while (stack)
	{
		if (stack->next)
			ft_printf("%d, ", stack->content);
		else
			ft_printf("%d", stack->content);
		stack = stack->next;
	}
	ft_printf("} | disorder: %f\n", disorder);
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

void	print_arr(void	*arr, size_t size)
{
	size_t	i;

	i = 0;
	ft_printf("{");
	while (i < size)
	{
		if (i != size - 1)
			ft_printf("%d, ", ((int *)arr)[i]);
		else
			ft_printf("%d ", ((int *)arr)[i]);
		i++;
	}
	ft_printf("}");
}

void	print_userinput(t_userinput *ui, const char *ui_name)
{
	if (!ui)
		return (ft_printf("%s (NULL USER INPUT)\n", ui_name), (void)0);
	ft_printf("%s { bench=%d, mode=%s, arr=", ui_name, ui->bench, ui->mode);
	print_arr(ui->arr, ui->arr_size);
	ft_printf(", arr_size=%u }\n", ui->arr_size);
}

int		is_stack_in_order(t_intlist *stack)
{
	t_intlist	*sk;

	while (stack)
	{
		sk = stack->next;
		while (sk)
		{
			if (sk->content < stack->content)
				return (0);
			sk = sk->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	test_user_input(char **av, int ac, t_userinput *expected, const char *name)
{
	t_userinput	*ui1;

	ui1 = 0;
	if (!parse_input(ac, av, &ui1))
	{
		if (expected)
		{
			PRINT_ERR(
					ft_printf("Failed to parse user input.\n");
			);
			free_userinput(&ui1);
			return (0);
		}
	}
	else if (userinput_cmp(ui1, expected))
	{
		PRINT_ERR(
				ft_printf("User input differs from expected:\n\n");
				print_userinput(expected, "expected:");
				print_userinput(ui1, "got:");
		);
		free_userinput(&ui1);
		return (0);
	}
	free_userinput(&ui1);
	PRINT_SUCCESS();
	return (1);
}

int	test_full(int argc, const char *args, int expected, const char *name)
{
	t_intlist	*stack_a;
	t_intlist	*stack_b;
	t_oparr		*oparr;
	t_userinput	*uinput;
	char		**split_args;

	stack_a = 0;
	stack_b = 0;
	oparr = 0;
	split_args = ft_split(args, ' ');
	if (!split_args)
	{
		PRINT_ERR(ft_printf("INTERNAL ERROR\nfailure from `ft_split`\n"););
		return (0);
	}
	if (!sort_stack(argc, split_args))
	{
		ft_cleanup(&stack_a, &stack_b, &oparr, &uinput);
		ft_freesplit(split_args);
		if (expected)
		{
			PRINT_ERR(ft_printf("Sorting stack failed.\n"););
			return (0);
		}
		else
		{
			PRINT_SUCCESS();
			return (1);
		}
	}
	if (!parse_input(argc, split_args, &uinput))
	{
		ft_cleanup(&stack_a, &stack_b, &oparr, &uinput);
		ft_freesplit(split_args);
		if (expected)
		{
			PRINT_ERR(ft_printf("Input parsing failed.\n"););
			return (0);
		}
		else
		{
			PRINT_SUCCESS();
			return (1);
		}
	}
	if (!select_algo(&stack_a, &stack_b, &oparr, &uinput))
	{
		ft_cleanup(&stack_a, &stack_b, &oparr, &uinput);
		ft_freesplit(split_args);
		if (expected)
		{
			PRINT_ERR(ft_printf("Running algorithm failed.\n"););
			return (0);
		}
		else
		{
			PRINT_SUCCESS();
			return (1);
		}
	}
	if (!is_stack_in_order(stack_a))
	{
		ft_freesplit(split_args);
		PRINT_ERR(
				ft_printf("Stack order is not right!\n");
				print_stack(stack_a, "Stack");
				);
		ft_cleanup(&stack_a, &stack_b, &oparr, &uinput);
		return (0);
	}
	ft_cleanup(&stack_a, &stack_b, &oparr, &uinput);
	ft_freesplit(split_args);
	PRINT_SUCCESS();
	return (1);
}

int	test_stack_order(t_intlist *stack, const char *name)
{
	if (!is_stack_in_order(stack))
	{
		PRINT_ERR(
				ft_printf("Stack order is not right!\n");
				print_stack(stack, "Stack");
				);
		return (0);
	}
	PRINT_SUCCESS();
	return (1);
}

int	test_stack_disorder(t_intlist *stack, int expected, const char *name)
{
	int	real_disorder;

	real_disorder = compute_disorder(stack);
	if (expected != real_disorder)
	{
		PRINT_ERR(
				ft_printf("Real disorder: %d\nExpected disorder: %d\n", real_disorder, expected);
				);
		print_stack(stack, "Stack");
		return (0);
	}
	PRINT_SUCCESS();
	return (1);
}

int	arr_cmp(int *arr1, int *arr2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr1[i] != arr2[i])
			return (1);
		i++;
	}
	return (0);
}

int	userinput_cmp(t_userinput *ui1, t_userinput *ui2)
{
	if ((!ui1 && ui2) || (ui1 && !ui2))
		return (1);
	if (ft_strcmp(ui1->mode, ui2->mode))
		return (1);
	if (ui1->bench != ui2->bench)
		return (1);
	if (ui1->arr_size != ui2->arr_size)
		return (1);
	if (arr_cmp(ui1->arr, ui2->arr, ui1->arr_size))
		return (1);
	return (0);
}

t_intlist	*generate_random_stack(size_t size)
{
	int			i;
	int			j;
	int			tmp;
	int			*arr;
	t_intlist	*new;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while ((size_t)i < size)
	{
		arr[i] = i;
		i++;
	}
	i = size - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i--;
	}
	new = get_stack_from_arr(arr, size);
	free(arr);
	return (new);
}

