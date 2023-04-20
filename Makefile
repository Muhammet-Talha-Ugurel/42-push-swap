#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 04:45:20 by mugurel           #+#    #+#              #
#    Updated: 2023/02/06 04:45:22 by mugurel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ./src/push_swap.c ./src/rules.c ./src/stack_utils.c ./src/opt.c ./src/aec_alg.c
SRCBS = 
NAME = push_swap
CC = gcc
CFLAGS =  -g -Wall -Wextra -Werror
LFLAGS = -I./include/ -I./lib/get_next_line_lib/include/ -I./lib/ft_printf/includes/ -I./lib/libft/
LIBFT = ./lib/libft/libft.a
FT_PRINTF = ./lib/ft_printf/libftprintf.a
GET_NEXT_LINE = ./lib/get_next_line_lib/get_next_line.a
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS) $(FT_PRINTF) $(GET_NEXT_LINE) $(LIBFT)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

bonus : $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE) $(LIBFT) 
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

$(FT_PRINTF):
	@make -C ./lib/ft_printf

$(GET_NEXT_LINE):
	@make -C ./lib/get_next_line_lib

$(LIBFT):
	@make -C ./lib/libft

clean:

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./lib/ft_printf
	@make fclean -C ./lib/get_next_line_lib
	@make fclean -C ./lib/libft

re: fclean all

.PHONY: all bonus clean fclean re 
