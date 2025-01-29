/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:49:34 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/22 18:32:56 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief The bottom element of the stack is sent to the top.
 */
void	rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_tail;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tail = lstlast(*stack);
	before_tail = tail->prev;
	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	before_tail->next = NULL;
	*stack = tail;
}

/**
 * @brief Sends the bottom element of stack a to the top.
 * Prints "rra" to the standard output.
 */
void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

/**
 * @brief Sends the bottom element of stack b to the top.
 * Prints "rrb" to the standard output.
 */
void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

/**
 * @brief Sends the bottom element of both stacks to the top.
 * Prints "rrr" to the standard output.
 */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
