/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:40:11 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/29 14:04:37 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the biggest number present.
 * @return The biggest number found.
 */
int	biggest_num(t_stack **stack_a)
{
	int		biggest;
	t_stack	*tmp;

	biggest = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

/**
 * @brief Checks how many bits a number has.
 * @return The number of bits of the number.
 */
int	maximum_bits(int biggest)
{
	int	max;

	max = 0;
	while (biggest > 0)
	{
		biggest >>= 1;
		max++;
	}
	return (max);
}

/**
 * @brief Cheacks whether the numbers in the stack are sorted.
 * @return 1: Stack is sorted.
 *
 * 0: Stack is not sorted.
 */
int	sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/**
 * @brief Checks how many nodes a linked list has.
 * @return The number of nodes the linked list has.
 */
int	ft_stack_size(t_stack **stack)
{
	int		count;
	t_stack	*tmp;

	tmp = *stack;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
