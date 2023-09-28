# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 16:24:26 by atucci            #+#    #+#              #
#    Updated: 2023/09/28 19:13:22 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------
# This sets the variable NAME to the name of the executable file that we will build.
NAME = fdf

#--------------------------------------------------
# This sets the variable SRC to a list of C source files that are needed to build the "fdf" executable.
SRC = ./fdf.c \
	  ./parsing.c \
	  ./utils.c \
	  ./connect.c \
	  ./windows_manag.c \
	  ./bresenham.c \

#--------------------------------------------------
# This sets the variable OBJS to a list of object files that need to be built from the SRC files.
OBJS = $(SRC:.c=.o)

#--------------------------------------------------
# This sets the variable HDRS to the path of the header file that is included in the project.
HDRS = ./fdf.h

#--------------------------------------------------
# This sets the variable RM to the command that will be used to remove files.
RM = rm -f

#--------------------------------------------------
# This sets the C compiler with specific warning flags.
CC = gcc -Wall -Wextra -Werror

#--------------------------------------------------
# This variable specifies the path to the libft library, which will be used in the project.
LIBFT = libft/libft.a

#--------------------------------------------------
# This variable specifies additional flags required for MiniLibX (mlx).
MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit 


#--------------------------------------------------
# this is for mlx_dir
MLX_DIR = ./mlx
#--------------------------------------------------
# Color codes for echo commands to make the output more visually informative.
GREEN := \033[1;32m
CYAN := \033[1;36m
YELLOW := \033[1;33m
RED := \033[1;31m
RESET := \033[0m

#--------------------------------------------------
# Corny emojis for fun and engaging output messages.
DANCING_EMOJI := 🕺
MIC_DROP_EMOJI := 🎤🎶
PARTY_EMOJI := 🎉
TRASH_EMOJI := 🗑️

#--------------------------------------------------
# Rule for compiling C source files into object files.
.c.o:
	${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

#--------------------------------------------------
# Rule for building the "fdf" executable.
$(NAME): $(OBJS)
	@echo "$(CYAN)$(DANCING_EMOJI)Building $(NAME)...$(DANCING_EMOJI)$(RESET)"
	$(MAKE) -C libft
	$(MAKE) -C mlx
	${CC} -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAG)
	@echo "$(GREEN)$(MIC_DROP_EMOJI)$(NAME) binary created successfully! $(MIC_DROP_EMOJI)$(RESET)"

#--------------------------------------------------
# Default target: building the "fdf" executable when running 'make all'.
all: $(NAME)

#--------------------------------------------------
# Rule for cleaning up generated object files.
clean:
	@echo "$(YELLOW)$(TRASH_EMOJI) Cleaning up object files...$(TRASH_EMOJI)$(RESET)"
	${RM} $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean

#--------------------------------------------------
# Rule for completely removing generated object files and the "fdf" executable.
fclean: clean
	@echo "$(YELLOW)Cleaning up $(NAME) binary...$(RESET)"
	${RM} $(NAME)
	$(MAKE) -C libft fclean

#--------------------------------------------------
# Download and install the MLX library if it is not already installed.
download_mlx:
	if [ -e $(MLX_DIR) ]; \
	then \
	echo "MiniLibX's directory detected"; \
	else \
	git clone git@github.com:42Paris/minilibx-linux.git \
	&& mv minilibx-linux mlx; fi

#--------------------------------------------------

#--------------------------------------------------
# Rule for recompiling the project from scratch.
re: fclean all

#--------------------------------------------------
# .PHONY targets to specify non-file targets.
.PHONY: all clean fclean re

