/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:45 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/14 00:50:53 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf.h"
#include "libft.h"

typedef struct s_info
{
	int		bench;
	int		*nbrs;
	char	*mode;
}	t_info;

typedef struct s_intlist {
	struct s_intlist	*next;
	int					content;
}	t_intlist;

// On the subject of operation counting:
// We essentially have at worst 10 operations, so we could just have a int op_counter[10], and each
// index represents the count of a specific op. E.g. sa, sa, sb -> op_counter[0] += 2; op_counter[1] += 1;
// 0 being the index for `sa` and 1 of `sb`.

// Helpers

// Creates a linked list from an array of integers.
t_intlist	*get_stack_from_arr(int *arr, size_t size);
// Frees an info struct or wtv
void	i_want_to_be_free(t_info *info);

// Linked list utils

// Swaps the position of two items of a linked list.
// This function assumes that both pointers point to the same linked list.
// Which actually does not change anything if they dont, its just ft_swap.
void	ft_lstswap(t_intlist *l1, t_intlist *l2);
// Returns the second to last item in the list
t_intlist	*ft_lstsecondtolast(t_intlist *lst);
// Returns the last item in the list
t_intlist	*ft_intlstlast(t_intlist *lst);
// Adds a list item to the back of the list
void	ft_intlstadd_back(t_intlist **lst, t_intlist *new);
// Creates a new list item
t_intlist	*ft_intlstnew(int content);
// Clears (frees) an entire list. Sets the pointer back to 0
void	ft_intlstclear(t_intlist **lst);

// Operations

// Executes a swap op. (sa, sb, ss) depending on the specified params.
// e.g. `op_swap(&stack_a, NULL)` will execute `sa`
void	op_swap(t_intlist *stack_a, t_intlist *stack_b);
// Pushes the item at the top of stack b onto the top of stack a
void	op_push_a(t_intlist *stack_a, t_intlist *stack_b);
// Pushes the item at the top of stack a onto the top of stack b
void	op_push_b(t_intlist *stack_a, t_intlist *stack_b);
// Executes a rotation op. (ra, rb, rr)
void	op_rotate(t_intlist **stack_a, t_intlist **stack_b);
// Executes a reverse rotation op. (rra, rrb, rrr)
void	op_reverse_rotate(t_intlist **stack_a, t_intlist **stack_b);

// Computes the disorder of a stack
double	compute_disorder(t_intlist *stack);
int		parse_input(int argc, char *args[], t_info *info);
t_info	*new_info(void);

#endif
