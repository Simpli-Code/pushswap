# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 10:38:30 by chruhin           #+#    #+#              #
#    Updated: 2024/03/07 11:31:38 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME				=		push_swap

# Directories
SRC_DIR				=		src
OBJ_DIR				=		obj
INC_DIR				=		inc

# Source files
DIRS				=		utils filtering sorting main
SRCS				=		$(foreach dir,$(DIRS),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))

# Object files
OBJS				=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Header files
INCS				=		$(addprefix -I, $(INC_DIR))

# Compiler flags
CFLAGS				=		-Wall -Wextra -Werror

# Cleanup
RM					=		rm -rf

# Targets
all:						$(OBJ_DIR) $(NAME)

# Create a Dir for obj
$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)
# Compiling obj
$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Compiling exec
$(NAME): 					$(OBJS)
							@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
							@printf "${GRN}Compiled successfuly${RST}\n"

# Remove object files
clean:
							@$(RM) $(OBJ_DIR)
							@printf "${RED}Deleted Object files${RST}\n"

# Remove obj & exec files
fclean:						clean
							@$(RM) $(NAME)
							@printf "${RED}and the Executable file${RST}\n"

# remove all & recompile
re:							fclean all

# No exceptions
.PHONY:						all clean fclean re

# color codes
RED					=		\e[1;31m
GRN					=		\e[1;32m
RST					=		\e[0m
