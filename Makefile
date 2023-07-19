# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 10:02:09 by atucci            #+#    #+#              #
#    Updated: 2023/07/19 10:02:30 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mlx-config-start make-subdirs norm \
		download-minilibx clean-minilibx
.DEFAULT_GOAL := $(NAME)
NAME := fdf
LIB := progfdf.a
LIBS := $(wildcard **/*.a)
SRCS := $(wildcard fdf*.c)
HEADERS := $(wildcard *.h)
OBJS := $(patsubst %.c, %.o, $(SRCS))
SUBDIRS := $(filter-out %mlx_linux/, $(wildcard */))
LIB_DIRS := $(addprefix ./, $(wildcard */))
LIB_FLAGS := $(addprefix -L, $(LIB_DIRS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O3 -g
LD_FLAGS := $(LIB_FLAGS) -lfdf -lmlx -lft -lXext -lX11 -lm

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) progfdf.a $(LD_FLAGS) -o $@

all: $(NAME)

$(LIB): mlx-config-start make-subdirs $(OBJS)
	ar rcs $@ $(OBJS) $(HEADERS) $(LIBS)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -c $^

mlx-config-start:
	cd mlx_linux && ./configure

make-subdirs:
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir; done

clean:
	rm -f $(OBJS) $(wildcard **/*.o) $(wildcard *.gch) $(wildcard **/*.gch)

fclean: clean
	rm -f $(LIBS) $(LIB) $(NAME)

re: fclean all

download-minilibx:
	git clone git@github.com:42Paris/minilibx-linux.git
	mv minilibx-linux mlx_linux

clean-minilibx: fclean
	rm -rfd mlx_linux

norm:
	norminette $(filter-out mlx_linux/%, $(SRCS) $(wildcard **/*.c))
