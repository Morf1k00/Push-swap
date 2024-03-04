# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 16:30:54 by rkrechun          #+#    #+#              #
#    Updated: 2024/03/04 13:39:52 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -O2 #-fsanitize=address -fno-omit-frame-pointer

MAKE_LIB = ar -rcs

SRCS = handle_errors.c \
				init_a_to_b.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				sort_three.c \
				sort_utils.c \
				stack_init.c \
				stack_utils.c \
				swap.c \
				split.c \
				
SRCS_BONUS =	get_next_line.c \
				get_next_line_utils.c \

PUSH_SWAP = 	main.c  \

CHECKER = checker.c \

OBJS_SRCS = $(SRCS:%.c=%.o)

OBJS_SRCS_BON = $(SRCS_BONUS:%.c=%.o)

OBJS_PUSH_SWAP = $(PUSH_SWAP:%.c=%.o)

OBJS_CHECKER = $(CHECKER:%.c=%.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJS_PUSH_SWAP) $(OBJS_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS): $(OBJS_CHECKER) $(OBJS_SRCS_BON) $(OBJS_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_SRCS) $(OBJS_SRCS_BON)

fclean : clean
	rm -f $(NAME) $(BONUS) 

re : fclean all

rebonus : fclean bonus

both : all bonus

reboth : fclean both

.PHONY : all clean fclean re