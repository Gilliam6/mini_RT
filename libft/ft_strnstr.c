/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:46:50 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:46:51 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		counter;

	if (needle[0] == 0 || haystack == needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			counter = 0;
			while (haystack[counter] && needle[counter] == haystack[counter]
				&& len--)
				counter++;
			if (needle[counter] == 0)
				return ((char *)haystack);
			len += counter;
		}
		haystack++;
		len--;
	}
	return (0);
}
