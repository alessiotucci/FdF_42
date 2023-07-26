# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 16:47:20 by fporciel          #+#    #+#              #
#    Updated: 2023/07/26 13:41:42 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# 
# This software is made available to anyone who wants to retrace the 
# author's learning path through the projects of school 42.
# Copyright (C) 2023  fporciel
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# You can contact the author at: 
#- fporciel@student.42roma.it
#

# Define color macros
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m

.PHONY: all clean fclean re mlx_config make_subdirs norm download_mlx \
		clean_mlx bonus rebonus
.DEFAULT_GOAL := $(NAME)
NAME := fdf
LIB := libfdf.a
LIB_BONUS := libfdf_bonus.a
LIBS := mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a libft/libft.a
SRCS := $(filter-out %bonus.c,$(wildcard fdf*.c))
BONUS_SRCS := $(wildcard fdf*_bonus.c)
HEADERS := fdf.h libft/libft.h $(wildcard mlx_linux/*.h)
BONUS_HEADERS := fdf_bonus.h libft/libft.h $(wildcard mlx_linux/*.h)
OBJS := $(patsubst %.c, %.o, $(SRCS))
BONUS_OBJS := $(patsubst %.c, %.o, $(BONUS_SRCS))
SUBDIRS := libft/ mlx_linux/
LIB_DIRS := $(addprefix ./, $(SUBDIRS))
LIB_FLAGS := $(addprefix -L, $(LIB_DIRS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O3 -g
LD_FLAGS := $(LIB_FLAGS) -lmlx -lft -lXext -lX11 -lm

# Compilation for the main program
$(NAME): $(LIB)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf.a $(LD_FLAGS) -o $@
	@echo "$(NAME) compiled successfully! 🚀"

all: $(NAME)

# Compilation for the bonus program
bonus: $(LIB_BONUS)
	@echo "Compiling bonus program..."
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf_bonus.a $(LD_FLAGS) -o fdf_bonus
	@echo "$(GREEN)Bonus program compiled successfully! 🌟$(RESET)"

# Building the static library
$(LIB): mlx_config make_subdirs $(OBJS)
	@echo "Building static library $(LIB)..."
	ar rcs $@ $(OBJS) $(HEADERS) $(LIBS)
	@echo "$(LIB) built successfully! 📚"

$(LIB_BONUS): mlx_config make_subdirs $(BONUS_OBJS)
	@echo "Building static library $(LIB_BONUS)..."
	ar rcs $@ $(BONUS_OBJS) $(BONUS_HEADERS) $(LIBS)
	@echo "$(GREEN) $(LIB_BONUS) built successfully! 📚 $(RESET)"

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -c $^

$(BONUS_OBJS): $(BONUS_SRCS) $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c $^

# Configuring the minilibx
mlx_config:
	@echo "Configuring minilibx..."
	cd mlx_linux && ./configure
	@echo "Minilibx configured successfully! ✨"

# Building subdirectories
make_subdirs:
	@echo "Building subdirectories..."
	for dir in $(filter-out mlx_linux/,$(SUBDIRS)); do $(MAKE) -C $$dir; done
	@echo "Subdirectories built successfully! 🏗️"

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS) $(BONUS_OBJS) $(wildcard **/*.o) $(wildcard *.gch) $(wildcard **/*.gch)
	@echo "Object files cleaned up! 🧹"

fclean: clean
	@echo "Cleaning up generated files..."
	rm -f $(LIBS) $(LIB) $(LIB_BONUS) fdf
	@echo "All generated files cleaned up! 🗑️"

re: fclean all

rebonus: fclean bonus

# Cloning and cleaning minilibx
download_mlx:
	@echo "Downloading minilibx..."
	git clone git@github.com:42Paris/minilibx-linux.git
	mv minilibx-linux mlx_linux
	@echo "Minilibx downloaded successfully! 🚀"

clean_mlx: fclean
	@echo "Cleaning minilibx..."
	rm -rfd mlx_linux
	@echo "Minilibx cleaned up! 🧹"

norm:
	@echo "Running norminette..."
	norminette $(filter-out mlx_linux/%, $(SRCS_FILES) $(wildcard **/*.c) $(HEADERS) $(BONUS_HEADERS))
	@echo "Norminette check completed! 📏"

