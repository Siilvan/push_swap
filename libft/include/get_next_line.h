/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 16:47:34 by ngero             #+#    #+#             */
/*   Updated: 2026/10/05 19:24:59 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_LINE_SIZE 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_ofbuffer
{
	char				*buffer;
	size_t				buf_size;
	unsigned long		chars;
}						t_ofbuffer;

char	*get_next_line(int fd);
// Helpers
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
// Reads the next `BUFFER_SIZE` chunk into the overflow buffer.
int		read_next_chunk(int fd, t_ofbuffer *overflow_buf);
// Realloc implementation
void	*ft_realloc(void **s, size_t *current_size);
// Extracts a chunk from the overflow buffer, memmoves the remaining characters
// back by the amount of characters extracted.
char	*extract_chunk_from_overflow_buf(char *until, t_ofbuffer *overflow_buf);
#endif
