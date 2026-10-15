# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 13:02:26 by sgroenve          #+#    #+#              #
#    Updated: 2026/10/14 00:31:46 by ngero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
INCLUDES		= -I./include/ -I./ft_printf -I./ft_printf/libft
CFLAGS			= -Wall -Wextra -Werror $(INCLUDES) -g3
NAME			= push_swap
SOURCES_DIR		= ./src
SOURCES			= disorder.c helpers.c lst_utils2.c lst_utils.c operations.c operations_r.c parse_input.c t_info.c
SOURCES			:= $(addprefix ./src/, $(SOURCES))
OBJECTS			= $(SOURCES:.c=.o)
FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a

# TEST
TEST_SOURCES 	= main.c tester_utils.c
TEST_SOURCES 	:= $(addprefix ./src/.tests/, $(TEST_SOURCES))
TEST_OBJECTS	= $(TEST_SOURCES:.c=.o)


all: other_libs $(NAME)

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(OBJECTS) $(FT_PRINTF)

other_libs:
	$(MAKE) -C $(FT_PRINTF_DIR)

test: testclean other_libs $(OBJECTS) $(TEST_OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(OBJECTS) $(TEST_OBJECTS) $(FT_PRINTF)

testclean:
	rm -f $(OBJECTS)
	rm -f $(TEST_OBJECTS)
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all
