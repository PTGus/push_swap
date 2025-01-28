/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:23:31 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/22 20:30:01 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **stack, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	if (!init_stack(stack_a, argc, argv))
	{
		ft_error(stack_a, stack_b);
		return (0);
	}
	indexer(stack_a);
	sorter(stack_a, stack_b);
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
	return (1);
}

int	init_stack(t_stack **stack, int argc, char **argv)
{
	if (argc == 2 && is_valid(argv[1]) == 0)
	{
		if (!parse_args_str(argv, stack))
			return (0);
	}
	else if (argc >= 3)
	{
		if (!parse_args(argv, stack))
			return (0);
	}
	return (1);
}
