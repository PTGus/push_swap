/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:03:33 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 13:09:13 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Deletes an element of the list
 *  @param lst  list
 * 	@param del  address of the function that can delete the element's content
*/
void	ft_lstdelone(t_block *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
