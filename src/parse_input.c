/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:46:19 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/15 14:09:57 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_flag(char *arg, char **mode, int *bench)
{
	if(!ft_strcmp(arg, "--bench"))
		*bench = 1;
	else if (!ft_strcmp(arg, "--simple") || !ft_strcmp(arg, "--medium"))
		*mode = arg + 2;
	else if (!ft_strcmp(arg, "--complex") || !ft_strcmp(arg, "--adaptive"))
		*mode = arg + 2;
	else
		error_exit(NULL);
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

void	check_dupes(char **nbrs, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_strcmp(nbrs[j], nbrs[i]) == 0)
			error_exit();
		j++;
	}
}

int	*parse_numbers(char **nbrs)
{
	int	i;
	int	*nbr_arr;

	i = 0;
	while(nbrs[i])
		i++;
	nbr_arr = ft_calloc(i, sizeof(int));
	i = 0;
	while (nbrs[i])
	{
		if (check_number_format(nbrs[i]) == 0)
			error_exit();
		check_dupes(nbrs, i);
		nbr_arr[i] = ft_atoi(nbrs[i]);
		i++;
	}
	return (nbr_arr);
}

int	*parse_input(int argc, char *args[], char **mode, int *bench)
{
	int		i;
	int		j;
	char	**nbrs;

	i = 1;
	while (i < argc && !ft_strncmp(args[i], "--", 2))
	{
		handle_flag(args[i], mode, bench);
		i++;
	}
	if (i >= argc)
		error_exit(NULL);
	j = 0;
	if (argc - i == 1)
		nbrs = ft_split(args[i], ' ');
	else
	{
		nbrs = ft_calloc((argc - i) + 1, sizeof(char *));
		if (!nbrs)
			return (NULL);
		while (i < argc)
			nbrs[j++] = args[i++];
		nbrs[j] = 0;
	}
	return (parse_numbers(nbrs));
}
