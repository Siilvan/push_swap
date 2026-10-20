/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:24:42 by ngero             #+#    #+#             */
/*   Updated: 2026/10/05 20:18:49 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	if (src < dest)
	{
		while (n--)
			*((char *)dest + n) = *((char *)src + n);
	}
	else
	{
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	return (dest);
}

void	*ft_realloc(void **s, size_t *current_size)
{
	void	*new;

	new = malloc(*current_size * 2);
	if (!new)
		return (0);
	ft_memmove(new, *s, *current_size);
	free(*s);
	*s = new;
	*current_size = *current_size * 2;
	return (new);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}

int	read_next_chunk(int fd, t_ofbuffer	*overflow_buf)
{
	char		*chunk;
	ssize_t		output;

	if ((size_t)BUFFER_SIZE > overflow_buf->buf_size - overflow_buf->chars)
	{
		chunk = malloc(BUFFER_SIZE * sizeof(char));
		if (!chunk)
			return (-1);
		output = read(fd, chunk, BUFFER_SIZE);
		if (output <= 0)
			return (free(chunk), output);
		while ((size_t)output > overflow_buf->buf_size - overflow_buf->chars)
			if (!ft_realloc((void *)&overflow_buf->buffer,
					&overflow_buf->buf_size))
				return (free(chunk), -1);
		ft_memmove(overflow_buf->buffer + overflow_buf->chars, chunk, output);
		free(chunk);
	}
	else
		output = read(fd, overflow_buf->buffer + overflow_buf->chars,
				BUFFER_SIZE);
	if (output > 0)
		overflow_buf->chars += output;
	return (output);
}

char	*extract_chunk_from_overflow_buf(char *until, t_ofbuffer *overflow_buf)
{
	size_t	len;
	char	*s;

	if (!overflow_buf || !until)
		return (0);
	len = until - (char *)overflow_buf->buffer + 1;
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	ft_memmove(s, overflow_buf->buffer, len);
	s[len] = 0;
	ft_memmove(overflow_buf->buffer, until + 1, overflow_buf->chars - len);
	overflow_buf->chars -= len;
	return (s);
}
