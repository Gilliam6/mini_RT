/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:43:04 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:43:05 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	marker;
	unsigned char	*dst_cpy;

	dst_cpy = dst;
	marker = c;
	while (len--)
	{
		*dst_cpy = *(unsigned char *)src;
		if (*(unsigned char *)src == marker)
		{
			dst_cpy++;
			return (dst_cpy);
		}
		dst_cpy++;
		src++;
	}
	return (0);
}
