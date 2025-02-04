/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:27:24 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/04 10:46:20 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Frees all the nodes in a stack.
 */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/**
 * @brief Frees everything on program error
 *  and writes "Error" on std error.
 */
void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/**
 * @brief Checks whether an argument passed as
 *  a string fits the criteria to be utilized.
 */
int	is_valid(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	if (ft_strlen(str) > 11)
		return (0);
	if (!is_inside_range(str))
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Transform the members of a string
 *  from their ascii values into numbers.
 * @param str The string to be converted.
 * @return Number represented in paramaters as a long variable.
 */
long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	sum;

	sign = 1;
	i = 0;
	sum = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * sum);
}

/**
 * @brief Discovers the length of an array and returns it.
 * @param arr The array.
 * @return The length of the array.
 */
int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
