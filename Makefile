NAME := fdf

# Directories
SRCDIR := .
LIBFTDIR := libft
MLXDIR := mlx_linux

# Source Files
SRC := fdf.c fdf_bonus.c 
OBJ := $(SRC:.c=.o)

# Compiler and Flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O3 -g
LDFLAGS := -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lX11 -lXext -lm

# Check for multibinary project
BONUS_SRC := fdf_bonus.c
ifdef BONUS_SRC
	BONUS_NAME := fdf_bonus
endif

# Targets
all: $(NAME) $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_SRC:.c=.o)
	$(CC) $(CFLAGS) $(BONUS_SRC:.c=.o) $(LDFLAGS) -o $(BONUS_NAME)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Automatic Compilation of libft
libft:
	$(MAKE) -C $(LIBFTDIR)

# Automatic Compilation of mlx_linux
mlx:
	$(MAKE) -C $(MLXDIR)

# Cleaning rules
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

# Rebuild the project
re: fclean all

# Multibinary rule
both: all

.PHONY: all clean fclean re libft mlx both

