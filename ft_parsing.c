/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:26:48 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/23 14:25:37 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Gets last element of the list
 *  @param lst  list
 * 	@return Returns the last element of the list
*/
t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Creates a new node with the given value.
 * @param nbr The value that this new node will assume.
 * @return The new node.
 */
t_stack	*new_node(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nbr;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * @brief Adds a node to the end of the list, updates the head if necessary.
 */
void	ft_lst_back(t_stack **a, t_stack **curr)
{
	t_stack	*last;

	if (!*a)
	{
		*a = *curr;
		return ;
	}
	last = lstlast(*a);
	last->next = *curr;
	(*curr)->prev = last;
	return ;
}

/**
 * @brief Parses arguments and builds the linked list
 */
int	parse_args_str(char **argv, t_stack **a)
{
	int		i;
	t_stack	*curr;
	char	**split;

	if (!argv[1])
		return (0);
	split = ft_split(argv[1], ' ');
	if (!split)
		return (0);
	i = -1;
	while (split[++i])
	{
		if (ft_strlen(split[i]) > 11)
			return (0);
		if (!is_valid(split[i]))
			return (0);
		curr = new_node(ft_atol(split[i]));
		if (curr == NULL)
			return (0);
		ft_lst_back(a, &curr);
	}
	ft_free_split(split);
	if (!stack_is_valid(a))
		return (0);
	return (1);
}
