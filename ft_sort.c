/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:20:50 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/22 17:51:40 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Identifies which sorting mechanism should be followed.
 */
void	sorter(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = biggest_num(stack_a);
	if (!sorted(stack_a) && size <= 3)
		sort_three(stack_a);
	else if (!sorted(stack_a) && size <= 5)
		sort_five(stack_a, stack_b);
	else if (!sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
		ft_error(stack_a, stack_b);
}

/**
 * @brief Sorts three numbers.
 */
void	sort_three(t_stack **stack_a)
{
	int	biggest;

	biggest = biggest_num(stack_a);
	if ((*stack_a)->index == biggest)
		ra(stack_a);
	else if ((*stack_a)->next->index == biggest)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

/**
 * @brief Sorts five numbers.
 */
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = biggest_num(stack_a);
	while (size--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

/**
 * @brief Sorts the given amount of numbers.
 */
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	biggest;
	int	max_bits;
	int	i;
	int	j;

	biggest = biggest_num(stack_a);
	max_bits = maximum_bits(biggest);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < biggest)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
