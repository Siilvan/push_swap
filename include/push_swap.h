/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:44:45 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 11:27:08 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SA  0
# define SB  1
# define SS  2
# define PA  3
# define PB  4
# define RA  5
# define RB  6
# define RR  7
# define RRA 8
# define RRB 9
# define RRR 10

# include "libft.h"

typedef struct s_intlist {
	struct s_intlist	*next;
	int					content;
}	t_intlist;

// typedef struct operationarray_s {
// 	int *arr;
// 	int n_op;
// 	size_t arr_size;
// } oparr_t;

typedef struct operationarray_s {
	int arr[2000];
	int n_op;
	struct operationarray_s *next;
} t_oparr;
// On the subject of operation counting:
// We essentially have at worst 10 operations, so we could just have a int op_counter[10], and each
// index represents the count of a specific op. E.g. sa, sa, sb -> op_counter[0] += 2; op_counter[1] += 1;
// 0 being the index for `sa` and 1 of `sb`.

// Helpers

// Creates a linked list from an array of integers.
t_intlist	*get_stack_from_arr(int *arr, size_t size);
// strcmp
int		ft_strcmp(char *s1, char *s2);


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
// Returns the size of a list.
int	ft_intlstsize(t_intlist *lst);
// Clears (frees) an entire list. Sets the pointer back to 0
void	ft_intlstclear(t_intlist **lst);

// Operations

// Executes a swap op. (sa, sb, ss) depending on the specified params.
// e.g. `op_swap(&stack_a, NULL)` will execute `sa`
void	op_swap(t_intlist *stack_a, t_intlist *stack_b);
// Pushes the item at the top of stack b onto the top of stack a
void	op_push_a(t_intlist **stack_a, t_intlist **stack_b);
// Pushes the item at the top of stack a onto the top of stack b
void	op_push_b(t_intlist **stack_a, t_intlist **stack_b);
// Executes a rotation op. (ra, rb, rr)
void	op_rotate(t_intlist **stack_a, t_intlist **stack_b);
// Executes a reverse rotation op. (rra, rrb, rrr)
void	op_reverse_rotate(t_intlist **stack_a, t_intlist **stack_b);

// Algorithms

// Simple algorithm
void	algo_simple(t_intlist **stack_a, t_intlist **stack_b);

// Computes the disorder of a stack
double	compute_disorder(t_intlist *stack);
int		error_exit(t_intlist *stack_a, t_intlist *stack_b, t_oparr *oparr);
int		*parse_input(int argc, char *args[], char **mode, int *bench);

// Operation array stuff
t_oparr	*oparrnew(void);
void	clear_oparr(t_oparr **start);
int	ft_add_op(t_oparr *node, int op);

//algorthims
char	*adaptive_choose(double disorder)


#endif
