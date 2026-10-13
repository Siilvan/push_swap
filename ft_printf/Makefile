# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/10 12:38:55 by sgroenve          #+#    #+#              #
#    Updated: 2026/10/10 15:40:37 by sgroenve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
NAME        = libftprintf.a
SOURCES		= ft_printf.c ft_putchars_printf.c ft_format.c ft_flag.c ft_putnbr_printf.c\
				ft_printf_helper.c ft_putptr_printf.c
OBJECTS		= $(SOURCES:.c=.o)
LIBFT_DIR   = ./libft
LIBFT_OBJS  = $(LIBFT_DIR)/*.o
LIBFT       = $(LIBFT_DIR)/libft.a
BONUS_DIR	= ./bonus
BONUS_SRCS	= $(SOURCES:.c=_bonus.c)
BONUS_OBJS  = $(BONUS_SRCS:%.c=$(BONUS_DIR)/%.o)

all: other_libs $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(LIBFT_OBJS)

other_libs:
	make -C $(LIBFT_DIR)

bonus: other_libs $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS) $(LIBFT_OBJS)

clean:
	rm -f $(OBJECTS)
	rm -f $(LIBFT_OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all