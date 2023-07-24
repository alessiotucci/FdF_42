# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 16:47:20 by fporciel          #+#    #+#              #
#    Updated: 2023/07/22 15:01:44 by fporciel         ###   ########.fr        #
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

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf.a $(LD_FLAGS) -o $@

all: $(NAME)

bonus: $(LIB_BONUS)
	$(CC) $(CFLAGS) $(addprefix -I, $(LIB_DIRS)) libfdf_bonus.a $(LD_FLAGS) -o fdf

$(LIB): mlx_config make_subdirs $(OBJS)
	ar rcs $@ $(OBJS) $(HEADERS) $(LIBS)

$(LIB_BONUS): mlx_config make_subdirs $(BONUS_OBJS)
	ar rcs $@ $(BONUS_OBJS) $(BONUS_HEADERS) $(LIBS)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -c $^

$(BONUS_OBJS): $(BONUS_SRCS) $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c $^

mlx_config:
	cd mlx_linux && ./configure

make_subdirs:
	for dir in $(filter-out mlx_linux/,$(SUBDIRS)); do $(MAKE) -C $$dir; done

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(wildcard **/*.o) $(wildcard *.gch) $(wildcard **/*.gch)

fclean: clean
	rm -f $(LIBS) $(LIB) $(LIB_BONUS) fdf

re: fclean all

rebonus: fclean bonus

download_mlx:
	git clone git@github.com:42Paris/minilibx-linux.git
	mv minilibx-linux mlx_linux

clean_mlx: fclean
	rm -rfd mlx_linux

norm:
	norminette $(filter-out mlx_linux/%, $(SRCS_FILES) $(wildcard **/*.c) $(HEADERS) $(BONUS_HEADERS))

