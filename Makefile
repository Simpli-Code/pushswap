# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 10:38:30 by chruhin           #+#    #+#              #
#    Updated: 2023/06/21 14:24:00 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		push_swap

SRCS		=		push_swap.c is_input_valid.c create_list.c rules.c \
					small_sort.c big_sort.c clean_up.c ps_utils.c

OBJS		=		$(SRCS:.c=.o)

CFLAGS		=		-Wall -Wextra -Werror

RM			=		rm -f

.PHONY:				all clean fclean re

all:				$(NAME)

$(NAME):			$(OBJS)
					@cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
					@$(RM) $(OBJS)

fclean:				clean
					@$(RM) $(NAME)

re:					fclean all
