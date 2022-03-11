/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:46:30 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:46:32 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter])
		counter++;
	res = (char *)malloc(counter + 1);
	if (!res)
		return (0);
	counter = 0;
	while (s[counter])
	{
		res[counter] = f(counter, s[counter]);
		counter++;
	}
	res[counter] = 0;
	return (res);
}
