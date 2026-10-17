/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:46:19 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 18:47:30 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdlib.h"
#include <stddef.h>

int	handle_flag(char *arg, char **mode, int *bench)
{
	if(!ft_strcmp(arg, "--bench"))
		*bench = 1;
	else if (!ft_strcmp(arg, "--simple") || !ft_strcmp(arg, "--medium"))
		*mode = arg + 2;
	else if (!ft_strcmp(arg, "--complex") || !ft_strcmp(arg, "--adaptive"))
		*mode = arg + 2;
	else
		return (0);
	return (1);
}

int	check_number_format(char *str)
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

int	get_numbers_array(size_t size, char **argv, int **arr)
{
	size_t	i;
	size_t	dup_i;
	int		number;

	i = 0;
	*arr = malloc(size * sizeof(int));
	if (!*arr)
		return (0);
	while (i < size)
	{
		if (!check_number_format(argv[i]))
			return (0);
		number = ft_atoi(argv[i]);
		dup_i = 0;
		while (dup_i < i)
			if ((*arr)[dup_i++] == number)
				return (0);
		(*arr)[i] = ft_atoi(argv[i]);
		i++;
	}
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
	(*user_input)->bench = 0;
	i = 1;
	while (i < argc && !ft_strncmp(argv[i], "--", 2))
		if (!handle_flag(argv[i++], &(*user_input)->mode, &(*user_input)->bench))
			return (0);
	if (i >= argc)
		return (0);
	size = argc - i;
	(*user_input)->arr_size = size;
	if (!get_numbers_array(size, argv + i, &(*user_input)->arr))
	{
		free((*user_input)->arr);
		return (0);
	}
	return (1);
}
