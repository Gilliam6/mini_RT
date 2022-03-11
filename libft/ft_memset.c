/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:44:00 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:44:02 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *point, int c, size_t len)
{
	unsigned int	counter;

	counter = 0;
	c = (unsigned char)c;
	while (counter < len)
	{
		((unsigned char *)point)[counter] = c;
		counter++;
	}
	return (point);
}
