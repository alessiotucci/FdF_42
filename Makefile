# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    New_Makefile                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 09:30:37 by atucci            #+#    #+#              #
#    Updated: 2023/07/18 09:30:40 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This Makefile is used to build the "fdf" program.
# It automates the compilation and linking of C source files to create the final executable.
# Let's go through each section step by step, and explain basic concepts of Makefiles.

# Colors for echo commands
GREEN := \033[1;32m
CYAN := \033[1;36m
YELLOW := \033[1;33m
RED := \033[1;31m
RESET := \033[0m

# Phony targets: These are special targets that don't represent actual files.
# They are used to group common tasks that can be executed regardless of file existence.
# We have phony targets for building, cleaning, and other project-related actions.
.PHONY: all clean fclean re mlx config make_subdirs norm download_mlx clean_mlx bonus

# Set the default goal (default target) when running 'make' without specifying a target explicitly.
# In this case, the default target is "fdf," the name of the final executable.
.DEFAULT_GOAL := $(NAME)

# Variables: Variables in a Makefile store values for later use.
# Here, we define variables for the project name, library name, library directories, etc.
NAME := fdf
LIB := libfdf.a
LIBFT_DIR := libft/
MLX_DIR := mlx_linux/
BONUS_DIR := bonus
LIBFT_NAME := libft.a
LIBFT_FILES := $(LIBFT_DIR)/ $(LIBFT_NAME)
SRCS_FILES := $(wildcard **/fdf*.c) # those are all our sources files
SRCS := $(filter-out %$(BONUS_DIR)%.c,$(SRCS_FILES)) # Those are filtered out from the SRCS_FILES
BONUS_SRCS := $(filter-out $(NAME).c,$(SRCS_FILES))
HEADERS := fdf.h
BONUS_HEADERS := $(BONUS_DIR)/fdf_bonus.h
OBJS := $(patsubst %.c,%.o,$(SRCS))
BONUS_OBJS := $(patsubst %.c,%.o,$(BONUS_SRCS))
SUBDIRS := $(MLX_DIR) $(LIBFT_DIR)
LIB_DIRS := $(addprefix ./,$(SUBDIRS))
LIB_FLAGS := $(addprefix -L,$(LIB_DIRS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O3 -g
LD_FLAGS := $(LIB_FLAGS)

# Target for building the final executable "fdf."
# This rule specifies that "fdf" depends on the "libfdf.a" library (defined in $(LIB)).
$(NAME): $(LIB)
	@echo "$(CYAN)Building $(NAME) executable...$(RESET)"
	$(CC) $(CFLAGS) $(addprefix -I,$(LIB_DIRS)) $(LIB) $(LD_FLAGS) -o $@
	@echo "$(GREEN)$(NAME) executable created successfully!"

# Target for building all targets, which means building the final executable.
# This target is the default goal, so running 'make' will execute this rule.
all: $(NAME)

# Target for building the "libfdf.a" library.
# This rule specifies that "libfdf.a" depends on object files and headers.
$(LIB): $(OBJS)
	@echo "$(CYAN)Building $(LIB) static library...$(RESET)"
	ar rcs $@ $(OBJS)
	@echo "$(GREEN)$(LIB) static library created successfully!"

# Target for compiling C source files into object files.
# This rule specifies how to generate object files from C source files.
%.o: %.c $(HEADERS)
	@echo "$(CYAN)Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Target for building the bonus part (if any).
# Bonus files are filtered out and treated separately.
bonus: $(BONUS_OBJS)
	@echo "$(CYAN)building bonus part...$(RESET)"
	ar rcs $(LIB) $(BONUS_OBJS)
	@echo "$(GREEN)Bonus part built successfully!$(RESET)"

# Other targets and rules for various tasks like cleaning up build artifacts, etc.
# ...

# Clean up object files and the final executable.
clean:
	@echo "Cleaning up object files...$(RESET)"
	rm -f $(OBJS) $(wildcar **/*.o) $(wildcard *.gch) $(wildcard **.*.gch)
	@echo "$(GREEN)Object files cleaned up successfully!$(RESET)"

# Clean up object files, the final executable, and the library.
fclean: clean
	@echo "Cleaning up build artifacts and executables...$(RESET)"
	rm -f $(LIB) $(NAME)
	@echo "$(GREEN)Build artifacts and executables cleaned up successfully!$(RESET)"

# Perform a clean build by cleaning and then building all targets.
re: fclean all

# Target for configuring the minilibx library for the current environment (if applicable).
mlx:
	@echo "Configuring minilibx library...$(RESET)"
	cd $(MLX_DIR) && ./configure
	@echo "$(GREEN)Minilibx library configured successfully!$(RESET)"

# Target for recursively making subdirectories (like mlx_linux and libft).
make_subdirs:
	@echo "Building subdirectories...$(RESET)"
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir; done
	@echo "$(GREEN)Subdirectories built successfully!$(RESET)"

# Target for checking the source files for norminette compliance (coding style guidelines).
norm:
	@echo "Checking source files for norminette compliance...$(RESET)"
	norminette $(filter-out $(MLX_DIR)%,$(SRCS) $(wildcard **/*.c))
	@echo "$(GREEN)Norminette check completed!$(RESET)"

# Target for downloading the minilibx library for Linux (if needed).
download_mlx:
	@echo "Downloading minilibx library...$(RESET)"
	git clone git@github.com:42Paris/minilibx-linux.git $(MLX_DIR)
	@echo "$(GREEN)Minilibx library downloaded successfully!$(RESET)"

# Target for cleaning up the downloaded minilibx library and its build artifacts.
clean_mlx: fclean
	@echo "Cleaning up minilibx library...$(RESET)"
	rm -rfd $(MLX_DIR)
	@echo "$(GREEN)Minilibx library cleanup completed successfully!$(RESET)"

