# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 10:22:13 by atucci            #+#    #+#              #
#    Updated: 2023/07/26 10:22:37 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mlx_config make_subdirs norm download_mlx \
		clean_mlx bonus rebonus
.DEFAULT_GOAL := $(NAME)
NAME := fdf
LIB := libfdf.a
LIB_BONUS := libfdf_bonus.a
LIBS := mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a libft/libft.a
SRCS := $(filter-out %bonus%.c,$(wildcard fdf*.c))
BONUS_SRCS := $(wildcard *_bonus.c)
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
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf.a $(LD_FLAGS) -o $@
	@echo "$(NAME) compiled successfully! 🚀"

all: $(NAME)

# Compilation for the bonus program
bonus: $(LIB_BONUS)
	@echo "Compiling bonus program..."
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf_bonus.a $(LD_FLAGS) -o fdf
	@echo "Bonus program compiled successfully! 🌟"

# Building the static library
$(LIB): mlx_config make_subdirs $(OBJS)
	@echo "Building static library $(LIB)..."
	ar rcs $@ $(OBJS) $(HEADERS) $(LIBS)
	@echo "$(LIB) built successfully! 📚"

$(LIB_BONUS): mlx_config make_subdirs $(BONUS_OBJS)
	@echo "Building static library $(LIB_BONUS)..."
	ar rcs $@ $(BONUS_OBJS) $(BONUS_HEADERS) $(LIBS)
	@echo "$(LIB_BONUS) built successfully! 📚"

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

