/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:46:19 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/13 22:06:12 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(t_info *info)
{
	i_want_to_be_free(info);
	ft_putendl_fd("Error", 2);
	return (1);
}

int	parse_flags (int argc, char *args[], t_info *info)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strncmp(args[i], "--", 2))
		{
			if(!ft_strncmp(args[i], "--bench", 8))
				info->bench = 1;
			else if (!ft_strncmp(args[i], "--simple", 9))
				info->mode = args[i] + 2;
			else if (!ft_strncmp(args[i], "--medium", 9))
				info->mode = args[i] + 2;
			else if (!ft_strncmp(args[i], "--complex", 10))
				info->mode = args[i] + 2;
			else if (!ft_strncmp(args[i], "--adaptive", 11))
				info->mode = args[i] + 2;
			else
				error_exit(info);
		}
		else
			return (i);
		i++;
	}
	return (i);
}

int	check_numbers(char **nbrs, char *new, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (new[i] == '-')
		i++;
	while(ft_isdigit(new[i]) && new[i])
		i++;
	if (!(new[i] == '\0'))
		return (1);
	while (j < index)
	{
		if (!ft_strncmp(nbrs[j], new, ft_strlen(new)))
			return (1);
		else
			j++;
	}
	return (0);
}
void	parse_numbers(char **nbrs, int argc, t_info *info)
{
	int		i;
	char	**checked_nbrs;
	int		*int_nbrs;

	i = 0;
	int_nbrs = NULL;
	checked_nbrs = NULL;
	while (i < argc)
	{
		if (!check_numbers(checked_nbrs, nbrs[i], i))
		{
			checked_nbrs[i] = nbrs[i];
			int_nbrs[i] = ft_atoi(nbrs[i]);
		}
		else
			error_exit(info);
	}
	info->nbrs = int_nbrs;
}

int	parse_input(int argc, char *args[], t_info *info)
{
	int		i;
	char	**nbrs;
	
	nbrs = NULL;
	if(!ft_isdigit(args[1][0]) && ft_strncmp(args[1], "--", 2))
		return (1);
	i = parse_flags(argc, args, info);
	if (!(argc - i >= 0))
		error_exit(info);
	else if (argc - i == 0)
		nbrs = ft_split(args[i], ' ');
	else
	{
		while (i < argc)
		{
			nbrs[i] = args[i];
			ft_printf("here.\n");
			i++;
		}
	}
	parse_numbers(nbrs, argc - i, info);
	return (0);
}
