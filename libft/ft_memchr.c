/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:43:16 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:43:18 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	counter;
	unsigned char	*p;

	counter = 0;
	while (counter < n)
	{
		if (*((unsigned char *)s) == ((unsigned char)c))
		{
			p = ((unsigned char *)s);
			return (p);
		}
		s++;
		counter++;
	}
	return (p = 0);
}
