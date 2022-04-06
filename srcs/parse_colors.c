/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:43:27 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/06 18:43:28 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

t_color	color_fail(void)
{
	t_color	color;

	color.R = -1;
	color.B = -1;
	color.G = -1;
	return (color);
}

int	check_colors(t_color color)
{
	if (color.R < 0 || color.R > 255)
		return (0);
	if (color.G < 0 || color.G > 255)
		return (0);
	if (color.B < 0 || color.B > 255)
		return (0);
	return (1);
}

t_color	parse_colors(char **split)
{
	char		**rgb;
	t_color		color;

	rgb = ft_split(split[0], ',');
	if (!rgb)
		return (color_fail());
	color.R = ft_atoi(rgb[0]);
	color.G = ft_atoi(rgb[1]);
	color.B = ft_atoi(rgb[2]);
	if (rgb[3] || !check_colors(color))
	{
		stop_parse(rgb);
		return (color_fail());
	}
	stop_parse(rgb);
	return (color);
}
