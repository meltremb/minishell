# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 13:29:15 by meltremb          #+#    #+#              #
#    Updated: 2023/06/06 14:48:27 by meltremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE = @
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address
RM		=	rm -rf

# Libraries
LDIR	=	include/reworked-libft/
LIBFT	=	libft.a
RDIR	=	include/readline-8.2/
RLIB	=	libreadline.a
HLIB	=	libhistory.a
DBLDIR	=	include/dbl_lists/
DBLLIB	=	dbl_lists.a

# Dir and file names
NAME	=	minishell
SRCDIR	=	src/
OBJDIR	=	objs/
SRCS	=	src/minishell.c \
			src/syntaxer.c	\
			src/singleton.c \
			src/extras.c

OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: submodule $(NAME)

# Generates output file
$(NAME): $(LDIR)$(LIBFT) $(DBLDIR)$(DBLLIB) $(RDIR)$(RLIB) $(RDIR)$(HLIB) $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $^ -lcurses -o $@

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
		$(HIDE)mkdir -p $(OBJDIR)
		$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Generates libft
$(LDIR)$(LIBFT):
	-@ $(MAKE) -C $(LDIR)

# Generates readline
$(RDIR)$(RLIB):
	cd include/readline-8.2; ./configure && make

# Generates dbl_lists
$(DBLDIR)$(DBLLIB):
	-@ $(MAKE) -C $(DBLDIR)

valgrind: all
	$(HIDE)valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--show-reachable=yes \
	--track-fds=yes \
	--error-limit=no \
	--suppressions=./config/minishell.supp
	./minishell

norminette:
	$(HIDE)norminette include/
	$(HIDE)norminette src/
	$(HIDE)norminette reworked-libft/

# updates libft submodule
submodule:
	-@ git submodule update --init

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)
	$(HIDE)$(RM) $(OBJDIR)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(RM) $(DBLDIR)$(DBLLIB)

# Removes objects and executables and remakes
re: fclean all
