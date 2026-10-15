#include "ft_tester.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	print_stack(t_intlist *stack, const char *stack_name)
{
	double	disorder;

	disorder = compute_disorder(stack);
	if (!stack)
		return (printf("%s NULL_STACK\n", stack_name), (void)0);
	printf("%s {", stack_name);
	while (stack)
	{
		if (stack->next)
			printf("%d, ", stack->content);
		else
			printf("%d", stack->content);
		stack = stack->next;
	}
	printf("} | disorder: %f\n", disorder);
}

int	test_stack_order(t_intlist *stack)
{
	t_intlist	*sk;

	while (stack)
	{
		sk = stack->next;
		while (sk)
		{
			if (sk->content < stack->content)
			{
				PRINT_ERR("Stack order is not right!");
				print_stack(stack, "Stack");
				return (0);
			}
			sk = sk->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	test_stack_disorder(t_intlist *stack, int expected)
{
	int	real_disorder;

	real_disorder = compute_disorder(stack);
	if (expected != real_disorder)
	{
		PRINT_ERR("Real disorder: %d\nExpected disorder: %d\n", real_disorder, expected);
		print_stack(stack, "Stack");
		return (0);
	}
	return (1);
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

