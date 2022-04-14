/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:39:27 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:29:03 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

t_color	color_fail(void)
{
	t_color	color;

	color.r = -1;
	color.b = -1;
	color.g = -1;
	return (color);
}

int	check_colors(t_color color)
{
	if (color.r < 0 || color.r > 255)
		return (0);
	if (color.g < 0 || color.g > 255)
		return (0);
	if (color.b < 0 || color.b > 255)
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
	color.r = ft_atoi(rgb[0]);
	color.g = ft_atoi(rgb[1]);
	color.b = ft_atoi(rgb[2]);
	if (rgb[3] || !check_colors(color))
	{
		stop_parse(rgb);
		return (color_fail());
	}
	stop_parse(rgb);
	return (color);
}
