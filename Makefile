# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 13:29:15 by meltremb          #+#    #+#              #
#    Updated: 2023/05/31 14:03:55 by meltremb         ###   ########.fr        #
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
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

# Libraries
LDIR	=	reworked-libft/
LIBFT	=	libft.a

# Dir and file names
NAME	=	minishell
SRCDIR	=	src/
OBJDIR	=	objs/
SRCS	=	src/minishell.c \
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: submodule $(NAME)

# Generates output file
$(NAME): $(OBJS) $(LDIR)$(LIBFT)
	$(HIDE)$(CC) $(CFLAGS) $(LDIR)$(LIBFT) -o $@

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
		-@ $(HIDE)mkdir -p $(OBJDIR)
		-@ $(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Generates libft
$(LDIR)$(LIBFT):
	-@ $(MAKE) -C $(LDIR)

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

# Removes objects and executables and remakes
re: fclean all
