# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 13:02:26 by sgroenve          #+#    #+#              #
#    Updated: 2026/10/19 20:11:18 by ngero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
INCLUDES		= -I./include/ -I./libft/include
CFLAGS			= -Wall -Wextra -Werror $(INCLUDES)
NAME			= push_swap
SOURCES_DIR		= ./src
SOURCES			= disorder.c helpers.c lst_utils2.c lst_utils.c operations.c operations_r.c parse_input.c \
				  algorithms.c med_algo.c final_result.c bench_result.c oparr_utils.c complex_algo.c \
				  digit_ranks.c main.c freeing.c
SOURCES			:= $(addprefix ./src/, $(SOURCES))
OBJECTS			= $(SOURCES:.c=.o)
LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a

# TEST
TEST_SOURCES 	= main.c tester_utils.c
TEST_SOURCES 	:= $(addprefix ./src/.tests/, $(TEST_SOURCES))
TEST_OBJECTS	= $(TEST_SOURCES:.c=.o)

# Bonus
BONUS_NAME		= checker
BONUS_SOURCES	= $(addprefix ./src/checker/, main.c checker_utils.c) \
				  	$(addprefix ./src/, operations.c operations_r.c oparr_utils.c lst_utils.c lst_utils2.c \
					helpers.c freeing.c parse_input.c)
BONUS_OBJECTS	= $(BONUS_SOURCES:.c=.o)

all: other_libs $(NAME)

bonus: other_libs $(BONUS_NAME)

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(OBJECTS) $(LIBFT)

$(BONUS_NAME): $(BONUS_OBJECTS)
	cc -o $(BONUS_NAME) $(BONUS_OBJECTS) $(LIBFT)

other_libs:
	$(MAKE) -C $(LIBFT_DIR)

test: CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g3 -DTESTING=1 -fsanitize=address
test: testclean other_libs $(OBJECTS) $(TEST_OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(OBJECTS) $(TEST_OBJECTS) $(LIBFT)

testclean:
	rm -f $(OBJECTS)
	rm -f $(TEST_OBJECTS)
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
