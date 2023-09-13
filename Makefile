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

SRCS =	./src/push_swap.c					\
				./src/rules.c							\
				./src/rules1.c						\
				./src/rules2.c						\
				./src/push_swap_utils.c		\
				./src/push_swap_utils1.c	\
				./src/push_swap_utils2.c	\
				./src/opt.c								\
				./src/calc_opt.c					\
				./src/calc_opt2.c					\
				./src/mtu_sort.c					\
				./src/mtu_sort1.c					\
				./src/push_atoi.c					\
				./src/error_check.c

SRCBS = ./srcb/checker.c					\
				./srcb/checker_utils.c		\
				./srcb/rules.c							\
				./srcb/rules1.c						\
				./srcb/rules2.c						\
				./srcb/push_atoi_bonus.c					\
				./srcb/error_check.c

NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS =  -g -Wall -Wextra -Werror
LFLAGS = -I./include/ -I./lib/get_next_line_lib/include/ -I./lib/ft_printf/includes/
FT_PRINTF = ./lib/ft_printf/libftprintf.a
GET_NEXT_LINE = ./lib/get_next_line_lib/get_next_line.a
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

bonus : $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE)  
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME_BONUS)

$(FT_PRINTF):
	@make -C ./lib/ft_printf

$(GET_NEXT_LINE):
	@make -C ./lib/get_next_line_lib

clean:

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C ./lib/ft_printf
	@make fclean -C ./lib/get_next_line_lib

re: fclean all

.PHONY: all bonus clean fclean re 
