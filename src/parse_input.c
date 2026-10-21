/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:46:19 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/19 18:30:41 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "stdlib.h"
#include <stddef.h>

static int	handle_flag(char *arg, char **mode, int *bench)
{
	if (!ft_strcmp(arg, "--bench"))
		*bench = 1;
	else if (!ft_strcmp(arg, "--simple") || !ft_strcmp(arg, "--medium"))
		*mode = arg + 2;
	else if (!ft_strcmp(arg, "--complex") || !ft_strcmp(arg, "--adaptive"))
		*mode = arg + 2;
	else
		return (0);
	return (1);
}

static int	check_number_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_number(char *str, int *arr, size_t size, int *number)
{
	size_t	i;

	if (!check_number_format(str))
		return (0);
	*number = ft_atoi(str);
	i = 0;
	while (i < size)
		if (arr[i++] == *number)
			return (0);
	return (1);
}

int	get_numbers_array(size_t size, char **argv, int **arr)
{
	size_t	i;

	i = 0;
	if (size == 1)
		argv = ft_split(argv[0], ' ');
	*arr = malloc(get_numbers_size(size, argv) * sizeof(int));
	if (!*arr)
		return (0);
	while ((size == 1 && argv[i]) || i < size)
	{
		if (!parse_number(argv[i], *arr, i, &(*arr)[i]))
		{
			if (size == 1)
				ft_freesplit(argv);
			free(*arr);
			*arr = 0;
			return (0);
		}
		i++;
	}
	if (size == 1)
		ft_freesplit(argv);
	return (1);
}

int	parse_input(int argc, char **argv, t_userinput **user_input)
{
	int		i;
	int		size;

	if (argc < 2)
		return (0);
	*user_input = malloc(sizeof(t_userinput));
	if (!*user_input)
		return (0);
	(*user_input)->mode = "adaptive";
	(*user_input)->arr = 0;
	(*user_input)->bench = 0;
	i = 1;
	while (i < argc && !ft_strncmp(argv[i], "--", 2))
		if (!handle_flag(argv[i++], &(*user_input)->mode,
				&(*user_input)->bench))
			return (0);
	if (i >= argc)
		return (0);
	size = argc - i;
	(*user_input)->arr_size = size;
	if (!get_numbers_array(size, argv + i, &(*user_input)->arr))
		return (0);
	return (1);
}
