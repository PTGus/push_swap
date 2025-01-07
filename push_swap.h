/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:54:25 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 16:25:44 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include "printf/libftprintf.h"

typedef struct s_block
{
	int				value;
	unsigned int	binary;
	struct s_block	*data;
	struct s_block	*prev;
	struct s_block	*next;
}	t_block;

// ft_parsing/2 //
int		parse_args_str(char **argv, t_block *block);
t_block	*lstlast(t_block *lst);
long	ft_atol(const char *str);
t_block	*new_node(int nbr);
t_block	*ft_lst_back(t_block *block, t_block *curr);
int		parse_args(char **argv, t_block *block);
int		has_letter(char *str);

#endif
