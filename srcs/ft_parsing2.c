/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:55:50 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/30 16:00:15 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks whether a stack as any duplicate values.
 */
int	stack_is_valid(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;

	tmp = NULL;
	curr = *stack;
	while (curr != NULL)
	{
		tmp = curr->next;
		while (tmp != NULL)
		{
			if (curr->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (1);
}

/**
 * @brief Parses arguments when they are not passed
 *  as a single string and builds the linked list.
 */
int	create_new(t_stack **stack, char **arg, int start)
{
	t_stack	*curr;

	while (arg[start])
	{
		curr = NULL;
		curr = new_node(ft_atol(arg[start]));
		if (!curr)
			return (0);
		ft_lst_back(stack, curr);
		start++;
	}
	return (1);
}

/**
 * @brief Iterates through all the members of
 *  stack a and index thems from lowest value to highest.
 */
void	indexer(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*smallest;
	int		index;

	index = 0;
	while (1)
	{
		tmp = *stack_a;
		smallest = NULL;
		while (tmp)
		{
			if (tmp->index == -1 && (!smallest || tmp->value < smallest->value))
				smallest = tmp;
			tmp = tmp->next;
		}
		if (!smallest)
			break ;
		smallest->index = index;
		index++;
	}
}

/**
 * @brief Checks wether the given arguments are valid.
 */
int	valid_args(int argc, char **argv)
{
	if (is_single_number(argc, argv))
		return (0);
	if (argc == 2)
	{
		if (!parse_args_str(argv))
			return (0);
	}
	else if (argc >= 3)
	{
		if (!parse_args(argv))
			return (0);
	}
	return (1);
}
