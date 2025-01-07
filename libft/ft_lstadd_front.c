/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:27:51 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 13:10:30 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief Adds a new element to the beginning of the list
 *  @param lst - list
 * 	@param new - new element to add
*/
void	ft_lstadd_front(t_block **lst, t_block *new)
{
	new->next = *lst;
	*lst = new;
}

/* int main(void)
{
    t_block *list = NULL;
    t_block *elem1 = malloc(sizeof(t_block));
    t_block *elem2 = malloc(sizeof(t_block));
    t_block *elem3 = malloc(sizeof(t_block));
    elem1->content = "Element 1";
    elem2->content = "Element 2";
    elem3->content = "Element 3";
    ft_lstadd_front(&list, elem1);
    ft_lstadd_front(&list, elem2);
    ft_lstadd_front(&list, elem3);
    printf("Contents of the list:\n");
    t_block *current = list;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    free(elem1);
    free(elem2);
    free(elem3);
    return 0;
} */