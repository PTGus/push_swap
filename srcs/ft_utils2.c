/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:32 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/04 10:45:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_single_number(int argc, char **argv)
{
	int	i;
	int	count;

	if (argc == 2 && is_valid(argv[1]))
		return (1);
	else if (argc > 2)
	{
		i = 1;
		count = 0;
		while (i < argc)
		{
			if (is_valid(argv[i]) == 1)
				count++;
			i++;
		}
		if (count == 1)
			return (1);
	}
	return (0);
}

int	has_duplicates(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*checker;

	current = *stack_a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_inside_range(char *nbr)
{
	long	max_int;
	long	min_int;
	long	number;

	max_int = 2147483647;
	min_int = -2147483648;
	number = ft_atol(nbr);
	if ((number < min_int) || (number > max_int))
		return (0);
	return (1);
}
