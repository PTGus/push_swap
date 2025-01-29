/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:57:22 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/29 13:18:09 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = -1;
	if (!src)
		return (ft_strlen(dst));
	if (dstsize == 0)
		return (len);
	if (len + 1 < dstsize)
	{
		while (++i < len)
			dst[i] = src[i];
	}
	else
	{
		while (++i < dstsize - 1)
			dst[i] = src[i];
	}
	dst[i] = '\0';
	return (len);
}
