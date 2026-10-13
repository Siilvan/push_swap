# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 13:02:26 by sgroenve          #+#    #+#              #
#    Updated: 2026/10/13 13:52:37 by sgroenve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
INCLUDES		= -I./include/ -I./ft_printf -I./ft_printf/libft
CFLAGS			= -Wall -Wextra -Werror
NAME			= push_swap
SOURCES			= main.c helpers.c parse_input.c t_info.c
OBJECTS			= $(SOURCES:.c=.o)
FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a


all: other_libs $(NAME)

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(OBJECTS) $(FT_PRINTF)

other_libs:
	make -C $(FT_PRINTF_DIR)

test: clean $(OBJECTS)
	rm -f $(NAME)
	cc -o $(NAME) $(OBJECTS) $(FT_PRINTF)

clean:
	rm -f $(OBJECTS)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all
