# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 16:22:42 by gumendes          #+#    #+#              #
#    Updated: 2025/01/29 16:54:33 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs
BUILD_PATH = .build

# Source files with their full path (from srcs folder)
SRCS = $(SRC_PATH)/ft_clear.c $(SRC_PATH)/ft_lst_manip.c $(SRC_PATH)/ft_parsing.c $(SRC_PATH)/ft_parsing2.c $(SRC_PATH)/ft_push.c \
       $(SRC_PATH)/ft_rev_rotate.c $(SRC_PATH)/ft_rotate.c $(SRC_PATH)/ft_sort_util.c $(SRC_PATH)/ft_sort.c $(SRC_PATH)/ft_swap.c \
       $(SRC_PATH)/ft_utils.c $(SRC_PATH)/ft_utils2.c $(SRC_PATH)/main.c

# Object files directly in the .build folder (without any additional path)
OBJS = $(SRCS:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I.
RM = rm -rf
AR = ar rcs

LIBFT_PATH = libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

# Default rule to build the project
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARC)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)

# Rule to create object files in the .build folder
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Libft rule
$(LIBFT_ARC):
	@$(MAKE) -C $(LIBFT_PATH)

# Clean object files
clean:
	$(RM) $(BUILD_PATH)
	@$(MAKE) clean -C $(LIBFT_PATH)

# Clean everything
fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
