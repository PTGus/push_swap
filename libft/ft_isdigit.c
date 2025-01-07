/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:02:34 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/07 16:08:59 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief See if a certain character is a digit (0-9).
 *  @param c  Character.
 *  @return Returns 1 if not a digit and 0 if it is.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
