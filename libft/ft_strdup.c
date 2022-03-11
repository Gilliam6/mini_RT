/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:45:38 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:45:39 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*mem;
	unsigned int	counter;

	counter = 0;
	while (*s1)
	{
		s1++;
		counter++;
	}
	mem = (char *)malloc(counter + 1);
	if (!mem)
		return (0);
	mem[counter] = 0;
	s1--;
	while (counter--)
	{
		mem[counter] = *s1;
		s1--;
	}
	return (mem);
}
