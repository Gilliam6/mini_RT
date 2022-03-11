/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:46:01 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:46:02 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t
dstsize)
{
	size_t	counter;

	counter = 0;
	if (dstsize > 0)
	{
		while (dstsize-- && dst[counter])
			counter++;
		dstsize++;
		if (dstsize > 0)
		{
			dstsize--;
			while (dstsize-- && *src)
			{
				dst[counter] = *src;
				counter++;
				src++;
			}
			dst[counter] = 0;
		}
	}
	while (*src++)
		counter++;
	return (counter);
}
