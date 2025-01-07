# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:23:37 by gumendes          #+#    #+#              #
#    Updated: 2025/01/07 15:56:07 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags
CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g

# Library Paths
LIBFT_PATH		=	libft
PRINTF_PATH		=	printf

# Libraries
LIBFT		=	$(LIBFT_PATH)/libft.a
PRINTF		=	$(PRINTF_PATH)/libftprintf.a

# Includes
INCLUDES = -I$(LIBFT_PATH) -I$(PRINTF_PATH)

# Name of Output File
NAME		=	push_swap

# Source Files
SRC			=	main.c ft_parsing.c ft_parsing2.c

# Object Files
OBJ			=	$(SRC:.c=.o)

# Targets
all: $(LIBFT) $(PRINTF) $(NAME)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Build the printf library
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

# Build the push_swap program
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(INCLUDES)

# Clean object files
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

# Full clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
