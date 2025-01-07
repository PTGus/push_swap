/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:26:48 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 16:15:18 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/** @brief Gets last element of the list
 *  @param lst  list
 * 	@return Returns the last element of the list
*/
t_block	*lstlast(t_block *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Creates a new node with the given value.
 */
t_block	*new_node(int nbr)
{
	t_block	*new;

	new = malloc(sizeof(t_block));
	if (!new)
		return (NULL);
	new->value = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * @brief Adds a node to the end of the list, updates the head if necessary.
 */
t_block	*ft_lst_back(t_block *block, t_block *curr)
{
	t_block *last;

	if (!block)
	{
		block = curr;
		return (block);
	}
	last = lstlast(block);
	last->next = curr;
	curr->prev = last;
	return (block);
}

/**
 * @brief Parses arguments and builds the linked list
 */
int	parse_args_str(char **argv, t_block *block)
{
	int		i;
	t_block	*curr;
	char	**split;

	if (!argv[1])
		return (1);
	split = ft_split(argv[1], ' ');
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		if (ft_strlen(split[i]) > 11)
			return (1);
		curr = new_node(ft_atol(split[i]));
		if (!curr)
			return (1);
		ft_lst_back(block, curr);
		i++;
	}
	return (0);
}
