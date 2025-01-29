/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:09:23 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/29 14:50:39 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_del(void *content);

/**
 * @brief Iterates through the entire stack and frees every single node.
 */
void	ft_clear_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		ft_node_del(*stack);
		*stack = temp;
	}
	free(stack);
}

/**
 * @brief Checks whether a node exists and deletes if if so.
 */
void	ft_node_del(void *content)
{
	t_list	*node;

	node = (t_list *)content;
	if (node)
		free(node);
}

void	ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	single_dig(t_stack **stack_a, t_stack **stack_b)
{
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
	exit (1);
}
