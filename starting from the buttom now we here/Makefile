# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 14:11:22 by atucci            #+#    #+#              #
#    Updated: 2023/08/08 15:04:22 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME := fdf_bonus

# Directories
SRCDIR := .
LIBFTDIR := libft
MLXDIR := mlx_macos

# Source Files
SRC := fdf.c
OBJ := $(SRC:.c=.o)

# Compiler and Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror  -g
LDFLAGS := -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lX11 -lXext -lm

# Macro for mlx-specific flags
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

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

# Targets
all: libft mlx $(NAME)

$(NAME): $(OBJ)
	@echo "$(CYAN)Building $(DANCING_EMOJI)$(NAME) binary...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) binary created successfully! $(MIC_DROP_EMOJI)$(RESET)"

%.o: $(SRCDIR)/%.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully! $(PARTY_EMOJI)$(RESET)"

# Automatic Compilation of libft
libft:
	@echo "$(CYAN)Compiling libft library...$(RESET)"
	$(MAKE) -C $(LIBFTDIR)
	@echo "$(GREEN)libft library compiled successfully! $(PARTY_EMOJI)$(RESET)"

# Automatic Compilation of mlx
mlx:
	@echo "$(CYAN)Compiling mlx library...$(RESET)"
	$(MAKE) -C $(MLXDIR) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)mlx library compiled successfully! $(PARTY_EMOJI)$(RESET)"

# Cleaning rules
clean:
	@echo "$(YELLOW)Cleaning up object files...$(RESET)"
	rm -f $(OBJ)
	@echo "$(GREEN)Object files cleaned up successfully! $(PARTY_EMOJI)$(RESET)"
	@echo "$(YELLOW)Cleaning .o files of libft...$(RESET)"
	$(MAKE) -C $(LIBFTDIR) clean
	@echo "$(GREEN).o files of libft cleaned up successfully! $(TRASH_EMOJI)$(RESET)"
	@echo "$(YELLOW)Cleaning .o files of mlx_linux...$(RESET)"
	$(MAKE) -C $(MLXDIR) clean
	@echo "$(GREEN).o files of mlx cleaned up successfully! $(TRASH_EMOJI)$(RESET)"

fclean: clean
	@echo "$(YELLOW)Cleaning up $(NAME) binary...$(RESET)"
	rm -f $(NAME)
	@echo "$(GREEN)$(NAME) binary cleaned up successfully! $(PARTY_EMOJI)$(RESET)"
	@echo "$(YELLOW)Cleaning libft library...$(RESET)"
	$(MAKE) -C $(LIBFTDIR) fclean
	@echo "$(GREEN)libft library cleaned up successfully! $(TRASH_EMOJI)$(RESET)"

re: fclean all

# Bonus rule (same as all rule for now)
bonus: all

.PHONY: all clean fclean re libft mlx bonus

