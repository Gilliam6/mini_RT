/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:40:29 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 17:35:58 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	check_ints(char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			++counter;
		if (!isdigit(str[i]) && !(str[i] == ',' && str[i + 1] && i != 0))
			return (-1);
	}
	if (counter != 2)
		return (-1);
	return (0);
}

int	check_ony_one_int(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!isdigit(str[i]))
			return (-1);
	}
	return (0);
}

int	check_double_in_arr(char *str)
{
	char	**split;
	int		i;
	int		commas;

	i = -1;
	commas = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			++commas;
	}
	if (commas != 2)
		return (-1);
	split = ft_split(str, ',');
	i = -1;
	while (split[++i])
	{
		if (check_double(split[i], 1) == -1 || i > 2)
			return (-1 + stop_parse(split));
		if (split[i + 1])
			++commas;
	}
	return (0 + stop_parse(split));
}

int	check_double(char *str, int flag)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (flag == 1)
		++i;
	while (str[++i])
	{
		if (str[i] == '.')
			++count;
		if ((!isdigit(str[i]) && !(str[i] == '.' && i != 0)) || \
		count > 1 || (str[i] == '.' && !(str[i + 1])))
			return (-1);
	}
	return (0);
}
