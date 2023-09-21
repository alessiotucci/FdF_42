# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 16:24:26 by atucci            #+#    #+#              #
#    Updated: 2023/08/10 11:22:12 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#This sets the variable NAME to the name of the executable file that we will build.
NAME = fdf


#This sets the variable SRC to a list of C source files that are needed to build the push_swap executable.
SRC = ./fdf.c \
	  ./parsing.c \
	  ./utils.c \
	  ./connect.c \

#This sets the variable OBJS to a list of object files that need to be built from the SRC files.
OBJS = $(SRC:.c=.o)


#This sets the variable HDRS to the path of the header file that is included in the project.
HDRS = ./fdf.h


#This sets the variable RM to the command that will be used to remove files.
RM = rm -f


CC = gcc -Wall -Wextra -Werror

#I need to explain libft
LIBFT = libft/libft.a

MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

# Color codes for echo commands
GREEN := \033[1;32m
CYAN := \033[1;36m
YELLOW := \033[1;33m
RED := \033[1;31m
RESET := \033[0m

# Corny emojis
DANCING_EMOJI := 🕺
MIC_DROP_EMOJI := 🎤🎶
PARTY_EMOJI := 🎉
TRASH_EMOJI := 🗑️





.c.o:
	${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

#This is a rule that specifies how to build an object file from a C source file. It compiles the C file with the appropriate flags and options, and outputs the resulting object file.

$(NAME): $(OBJS)
	@echo "$(CYAN)$(DANCING_EMOJI)Building $(NAME)...$(DANCING_EMOJI)$(RESET)"
	$(MAKE) -C libft
	${CC} -o $(NAME) $(OBJS) $(LIBFT)
		@echo "$(GREEN)$(MIC_DROP_EMOJI)$(NAME) binary created successfully! $(MIC_DROP_EMOJI)$(RESET)"

#LET TRY ALONE
#$(NAME) : $(OBJS)
#	@echo "$(CYAN)I need to compile the mlx library$(RESET)"
#	$(MAKE) -C  mlx_macos 


all: $(NAME)



#This rule specifies how to clean up the generated object files.
clean:
	@echo "$(YELLOW)$(TRASH_EMOJI) Cleaning up object files...$(TRASH_EMOJI)$(RESET)"
	${RM} $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C mlx_macos clean


#This rule specifies how to completely remove the generated object files and the push_swap executable.
fclean: clean
	@echo "$(YELLOW)Cleaning up $(NAME) binary...$(RESET)"
	${RM} $(NAME)
	$(MAKE) -C libft fclean


re: fclean all


