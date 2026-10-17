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

int	test_user_input(char **av, int ac, t_userinput *expected, const char *name)
{
	t_userinput	*ui1;

	if (!parse_input(ac, av, &ui1))
	{
		if (expected)
		{
			PRINT_ERR(
					ft_printf("Failed to parse user input."););
			return (0);
		}
		PRINT_SUCCESS();
		return (1);
	}
	if (userinput_cmp(ui1, expected))
	{
		PRINT_ERR(
				ft_printf("User input differs from expected:\n\n");
				print_userinput(expected, "expected:");
				print_userinput(ui1, "got:");
		);
		return (0);
	}
	PRINT_SUCCESS();
	return (1);
}

int	test_stack_order(t_intlist *stack, const char *name)
{
	t_intlist	*sk;

	while (stack)
	{
		sk = stack->next;
		while (sk)
		{
			if (sk->content < stack->content)
			{
				PRINT_ERR(
						ft_printf("Stack order is not right!");
						);
				print_stack(stack, "Stack");
				return (0);
			}
			sk = sk->next;
		}
		stack = stack->next;
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

