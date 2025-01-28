# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:23:37 by gumendes          #+#    #+#              #
#    Updated: 2025/01/27 10:40:25 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                 Files and Paths                              #
#==============================================================================#

SRCS = ft_clear.c ft_lst_manip.c ft_parsing.c ft_parsing2.c ft_push.c ft_rev_rotate.c ft_rotate.c ft_sort_util.c \
			 ft_sort.c ft_swap.c ft_utils.c main.c

OBJS       = $(addprefix $(BUILD_PATH)/, $(SRCS:.c=.o))

NAME = push_swap

BUILD_PATH = .build

LIBFT_PATH = libft

LIBFT_ARC  = $(LIBFT_PATH)/libft.a

#==============================================================================#
#                                   Alias                                      #
#==============================================================================#

CC      = cc
AR      = ar rcs
RM      = rm -rf
CFLAGS  = -g -Wall -Werror -Wextra

#==============================================================================#
#                                    Rules                                     #
#==============================================================================#

all: $(NAME)

$(BUILD_PATH):
	@mkdir $(BUILD_PATH)

$(NAME): check $(BUILD_PATH) $(OBJS) $(LIBFT_ARC)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)
	@echo "$(GRN)[push_swap created!]$(D)"

$(BUILD_PATH)/%.o: %.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_ARC):
	@$(MAKE) -C $(LIBFT_PATH)

$(LIB_NAME): $(BUILD_PATH) $(OBJS)
	@$(AR) $(LIB_NAME) $(OBJS)

check:	## Download/Update libft
	@if test ! -d "$(LIBFT_PATH)"; then make -s get_libft; \
		else echo "$(GRN)[Libft folder found]$(D)"; fi

get_libft:
	@echo "[$(CYA)Downloading Libft$(D)]"
	git clone git@github.com:PTGus/libft.git $(LIBFT_PATH)
	@echo "$(CYA)[Libft successfully downloaded]$(D)"


clean:
	@$(RM) $(BUILD_PATH)
	@$(MAKE) clean -C $(LIBFT_PATH)
	@echo "$(BCYA)[clean] push_swap Objects removed$(D)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(BCYA)[fclean] push_swap Executable and Libft removed$(D)"

re: fclean all

re: fclean all

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)

.PHONY: all clean fclean re
