/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:23:31 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/30 16:09:35 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init(int argc, char **argv, t_stack ***stack_a, t_stack ***stack_b);
int	fill_stack(char **args, t_stack **stack, int type);
int	mal_check(t_stack ***stack_a, t_stack ***stack_b);

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc == 1)
		return (0);
	if (!valid_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!ft_init(argc, argv, &stack_a, &stack_b))
		return (0);
	if (has_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		ft_clear_stack(stack_a);
		ft_clear_stack(stack_b);
		return (0);
	}
	indexer(stack_a);
	sorter(stack_a, stack_b);
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
	return (1);
}

int	mal_check(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = malloc(sizeof(t_stack *));
	if (!*stack_a)
		return (0);
	*stack_b = malloc(sizeof(t_stack *));
	if (!*stack_b)
	{
		free(*stack_a);
		return (0);
	}
	**stack_a = NULL;
	**stack_b = NULL;
	return (1);
}

int	fill_stack(char **args, t_stack **stack, int type)
{
	if (type == 1)
	{
		create_new(stack, args, type);
		return (1);
	}
	else
	{
		create_new(stack, args, type);
		return (1);
	}
	return (0);
}

int	ft_init(int argc, char **argv, t_stack ***stack_a, t_stack ***stack_b)
{
	char	**split;

	if (argc > 2)
	{
		if (!mal_check(stack_a, stack_b))
			return (0);
		if (!fill_stack(argv, *stack_a, 1))
			return (0);
		return (1);
	}
	else
	{
		split = ft_split(argv[1], ' ');
		if (!mal_check(stack_a, stack_b))
			return (0);
		if (!fill_stack(split, *stack_a, 0))
			return (0);
		ft_free_split(split);
		return (1);
	}
	return (0);
}
