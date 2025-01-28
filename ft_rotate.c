/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:43:33 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/20 11:57:54 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief The top element of the stack is sent to the bottom.
 */
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tail = ft_lst_last(*stack);
	tmp->next = NULL;
	tmp->prev = tail;
	tail->next = tmp;
}

/**
 * @brief Sends the top element of stack a to the bottom.
 * Prints "ra" to the standard output.
 */
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

/**
 * @brief Sends the top element of stack b to the bottom.
 * Prints "rb" to the standard output.
 */
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/**
 * @brief Sends the top element of both stacks a and b to the bottom
 * of their respective stacks.
 * Prints "rr" to the standard output.
 */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
