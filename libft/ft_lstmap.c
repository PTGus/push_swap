/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:19:00 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 13:10:30 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Creates a new list resulting
 * from the application of f to each element
 *  @param lst - list
 * 	@param f - function to apply
 * 	@param del - function that can delete an element's content
 *  @return Returns a list
*/
t_block	*ft_lstmap(t_block *lst, void *(*f)(void *), void (*del)(void *))
{
	t_block	*new_lst;
	t_block	*new_obj;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		cont = f(lst->content);
		new_obj = ft_lstnew(cont);
		if (!new_obj)
		{
			del(cont);
			ft_lstclear(&new_lst, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_obj);
		lst = lst->next;
	}
	return (new_lst);
}
