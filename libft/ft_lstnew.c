/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:44:42 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 13:10:30 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Creates a new list node element
 *  @param content - content for the new element
 *  @return returns the new list
*/
t_block	*ft_lstnew(void *content)
{
	t_block	*new_node;

	new_node = malloc(sizeof(t_block));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
