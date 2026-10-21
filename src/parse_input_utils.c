/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:01:51 by ngero             #+#    #+#             */
/*   Updated: 2026/10/21 15:01:52 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	get_numbers_size(size_t size, char **av)
{
	size_t	real_size;

	real_size = 0;
	if (!av)
		return (0);
	if (size == 1)
	{
		while (av[real_size])
			real_size++;
		return (real_size);
	}
	return (size);
}
