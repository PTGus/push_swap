/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:54:25 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/29 15:30:55 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				biggest;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// ft_clear //
void	ft_clear_stack(t_stack **stack);
void	ft_node_del(void *content);
void	ft_free_split(char **split);
void	single_dig(t_stack **stack_a, t_stack **stack_b);

// ft_lst_manip //
t_stack	*ft_lst_last(t_stack *lst);

// ft_parsing/2 //
int		parse_args_str(char **argv);
t_stack	*lstlast(t_stack *lst);
long	ft_atol(const char *str);
t_stack	*new_node(int nbr);
void	ft_lst_back(t_stack **stack_a, t_stack *curr);
int		parse_args(char **argv);
int		has_letter(char *str);
void	indexer(t_stack **stack_a);
int		stack_is_valid(t_stack **stack);
int		valid_args(int argc, char **argv);
int		create_new(t_stack **stack, char **arg, int start);

// ft_push //
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// ft_rev_rotate //
void	rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// ft_rotate //
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// ft_swap //
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// ft_sort //
void	sorter(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// ft_utils/2 //
void	free_stack(t_stack **stack);
void	ft_error(t_stack **stack_a, t_stack **stack_b);
int		is_valid(char *str);
int		arr_len(char **arr);
int		is_single_number(int argc, char **argv);

// ft_sort_util //
int		biggest_num(t_stack **stack_a);
int		maximum_bits(int num);
int		sorted(t_stack **stack_a);
int		ft_stack_size(t_stack **stack);

// main //
int		mal_check(t_stack ***stack_a, t_stack ***stack_b);
int		ft_init(int argc, char **argv, t_stack ***stack_a, t_stack ***stack_b);
int		fill_stack(char **args, t_stack **stack, int type);

#endif
