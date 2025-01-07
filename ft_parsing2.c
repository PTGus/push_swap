/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:55:50 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 16:15:31 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_letter(char *str)
{
	size_t	i;

	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	parse_args(char **argv, t_block *block)
{
	size_t	i;
	t_block	*curr;

	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (1);
		if (has_letter(argv[i] == 1))
			return (1);
		curr = new_node(ft_atol(argv[i]));
		if (!curr)
			return (1);
		ft_lst_back(block, curr);
		i++;
	}
	return (0);
}
