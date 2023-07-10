NAME = fdf

#This sets the variable NAME to the name of the executable file that we will build.

SRC = ./fdf.c \
	  ./utils.c \
      ./parsing.c \
	  ./split_utils.c \
	 # srcs/moves2.c \
	  #srcs/quick_sort.c \

#This sets the variable SRC to a list of C source files that are needed to build the fdf  executable.

OBJS = $(SRC:.c=.o)

#This sets the variable OBJS to a list of object files that need to be built from the SRC files.

HDRS = ./fdf.h

#This sets the variable HDRS to the path of the header file that is included in the project.

RM = rm -f

#This sets the variable RM to the command that will be used to remove files. 
# updated because of the libraries needed and the frameworks

CC = gcc -Wall -Wextra -Werror 

OPENGL =-I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit 

#This sets the variable CC to the compiler command with warning flags enabled.

LIBFT = libft/libft.a

#This sets the variable LIBFT to the path of the static library file that we will link to our executable.

#trying to modifing the makefile

MINILIBX = minilibx_macos/libmlx.a

.c.o:
	${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

#This is a rule that specifies how to build an object file from a C source file. It compiles the C file with the appropriate flags and options, and outputs the resulting object file.

$(NAME): $(OBJS)
	$(MAKE) -C libft
	${CC} $(OPENGL) -o $(NAME) $(OBJS) $(LIBFT)

#This is the rule to build the fdf  executable. It depends on the object files generated by the .c.o rule and the libft library. It creates the executable by linking the object files with the library.

all: $(NAME)

#This rule specifies that running make without any arguments will build the fdf  executable.

clean:
	${RM} $(OBJS)
	$(MAKE) -C libft  clean

#This rule specifies how to clean up the generated object files.

fclean: clean
	${RM} $(NAME)
	$(MAKE) -C libft fclean

#This rule specifies how to completely remove the generated object files and the fdf  executable.

re: fclean all

#This rule specifies how to rebuild the project completely by removing all object files and rebuilding the fdf  executable.

.PHONY: all clean fclean re

#This declares the targets all, clean, fclean, and re as phony targets, which means that they don't correspond to actual files but instead are just names for actions that need to be performed.
