/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:23:31 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 16:28:12 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_block	*block;

	block = malloc(sizeof(t_block));
	if (!block)
		return (1);
	if (argc == 2)
	{
		if (!parse_args_str(argv, block))
			return (0);
	}
	else if (argc >= 3 && ft_isdigit(argv[2][0]) == 0)
	{
		parse_args(argv, block);
	}
	while (block)
	{
		ft_printf("%i\n", block->value);
		block = block->next;
	}
	ft_lstclear(&block, ft_lstdelone);
}
