/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:22:07 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/22 16:01:38 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element of src stack to the top of dst stack.
 */
void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL || src == NULL)
		return ;
	tmp = (*src)->next;
	if (tmp)
		tmp->prev = NULL;
	(*src)->next = *dst;
	if (*dst)
		(*dst)->prev = *src;
	(*src)->prev = NULL;
	*dst = *src;
	*src = tmp;
}

/**
 * @brief Pushes the top element of stack b to the top of stack a.
 * Prints "pa" to the standard output.
 */
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

/**
 * @brief Pushes the top element of stack a to the top of stack b.
 * Prints "pb" to the standard output.
 */
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
