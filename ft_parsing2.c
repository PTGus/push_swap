/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:55:50 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/27 09:53:52 by gumendes         ###   ########.fr       */
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
		if (curr->value > INT_MAX || curr->value < INT_MIN)
			return (0);
		curr = curr->next;
	}
	return (1);
}

/**
 * @brief Parses arguments when they are not passed
 *  as a single string and builds the linked list.
 */
int	parse_args(char **argv, t_stack **a)
{
	size_t	i;
	t_stack	*curr;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (0);
		if (!is_valid(argv[i]))
			return (0);
		curr = new_node(ft_atol(argv[i]));
		if (!curr)
			return (0);
		ft_lst_back(a, &curr);
		i++;
	}
	if (!stack_is_valid(a))
		return (0);
	return (1);
}

/**
 * @brief Iterates through all the members of
 *  stack_a and index thems from lowest value to highest.
 */
void	indexer(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*smallest;
	int		index;

	index = 1;
	while (1)
	{
		tmp = *stack_a;
		smallest = NULL;
		while (tmp)
		{
			if (tmp->index == 0 && (!smallest || tmp->value < smallest->value))
				smallest = tmp;
			tmp = tmp->next;
		}
		if (!smallest)
			break ;
		smallest->index = index;
		index++;
	}
}

int	is_out_of_int_range(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign * result) > INT_MAX || (sign * result) < INT_MIN)
			return (1);
		i++;
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}
