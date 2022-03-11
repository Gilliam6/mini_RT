/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:39:22 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:39:23 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	index;
	void	*mass;

	index = 0;
	mass = malloc(count * size);
	if (!mass)
		return (0);
	while (index < count * size)
	{
		((char *)mass)[index] = 0;
		index++;
	}
	return (mass);
}
