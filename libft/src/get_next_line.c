/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 15:01:49 by ngero             #+#    #+#             */
/*   Updated: 2026/10/05 17:31:02 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_buffer(t_ofbuffer **ob)
{
	if (*ob)
		return (1);
	*ob = malloc(sizeof(t_ofbuffer));
	if (!*ob)
		return (0);
	(*ob)->buffer = malloc(MAX_LINE_SIZE * sizeof(char));
	if (!((*ob)->buffer))
	{
		free(*ob);
		*ob = 0;
		return (0);
	}
	(*ob)->chars = 0;
	(*ob)->buf_size = MAX_LINE_SIZE;
	return (1);
}

static char	*free_buffer(t_ofbuffer **ob)
{
	if (!ob || !*ob)
		return (0);
	free((*ob)->buffer);
	free(*ob);
	*ob = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	static t_ofbuffer	*overflow_buf;
	int					routput;
	char				*nl_ptr;
	char				*chunk;

	if (fd < 0 || BUFFER_SIZE <= 0 || !get_buffer(&overflow_buf))
		return (0);
	if (overflow_buf->chars <= 0)
		if (read_next_chunk(fd, overflow_buf) <= 0)
			return (free_buffer(&overflow_buf));
	nl_ptr = ft_memchr(overflow_buf->buffer, '\n', overflow_buf->chars);
	while (!nl_ptr)
	{
		routput = read_next_chunk(fd, overflow_buf);
		if (!routput)
			nl_ptr = (char *)overflow_buf->buffer + overflow_buf->chars - 1;
		else if (routput < 0)
			return (free_buffer(&overflow_buf));
		else
			nl_ptr = ft_memchr(overflow_buf->buffer, '\n', overflow_buf->chars);
	}
	chunk = extract_chunk_from_overflow_buf(nl_ptr, overflow_buf);
	if (!chunk)
		return (free_buffer(&overflow_buf));
	return (chunk);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;
//
// 	if (ac != 2)
// 		return (printf("Usage:\n\t$ ./a.out [filename]\n"));
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (printf("Failed to read file.\n"));
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// }
