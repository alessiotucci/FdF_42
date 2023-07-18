.PHONY: all clean fclean re mlx_config make_subdirs norm download_mlx \
		clean_mlx bonus
.DEFAULT_GOAL := $(NAME)
NAME := fdf
LIB := libfdf.a
LIB_BONUS := libfdf_bonus.a
LIBS := mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a libft/libft.a
BONUS_DIR := bonus
SRCS_FILES := $(wildcard **/fdf*.c)
SRCS := $(filter-out %bonus%.c,$(SRCS_FILES))
BONUS_SRCS := $(filter-out $(SRCS),$(SRCS_FILES))
HEADERS := fdf.h libft/libft.h $(wildcard mlx_linux/*.h)
BONUS_HEADERS := $(BONUS_DIR)/fdf_bonus.h libft/libft.h $(wildcard mlx_linux/*.h)
OBJS := $(patsubst %.c, %.o, $(SRCS))
BONUS_OBJS := $(patsubst %.c, %.o, $(BONUS_SRCS))
SUBDIRS := mlx_linux/ libft/
LIB_DIRS := $(addprefix ./, $(SUBDIRS))
LIB_FLAGS := $(addprefix -L, $(LIB_DIRS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O3 -g
LD_FLAGS := $(LIB_FLAGS) -lmlx -lft -lXext -lX11 -lm

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf.a $(LD_FLAGS) -o $@

all: $(NAME)

bonus: $(LIB_BONUS)
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf_bonus.a $(LD_FLAGS) -o fdf

$(LIB): mlx_config make_subdirs $(OBJS)
	ar rcs $@ $(OBJS) $(HEADERS) $(LIBS)

$(LIB_BONUS): mlx_config make_subdirs $(BONUS_OBJS)
	ar rcs $@ $(OBJS) $(BONUS_HEADERS) $(LIBS)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -c $^

$(BONUS_OBJS): $(BONUS_SRCS) $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c $^

mlx_config:
	cd mlx_linux && ./configure

make_subdirs:
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir; done

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(wildcard **/*.o) $(wildcard *.gch) $(wildcard **/*.gch)

fclean: clean
	rm -f $(LIBS) $(LIB) $(LIB_BONUS) fdf

re: fclean all

download_mlx:
	git clone git@github.com:42Paris/minilibx-linux.git
	mv minilibx-linux mlx_linux

clean_mlx: fclean
	rm -rfd mlx_linux

norm:
	norminette $(filter-out mlx_linux/%, $(SRCS_FILES) $(wildcard **/*.c) $(HEADERS) $(BONUS_HEADERS))
