/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:40:05 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/07 16:24:10 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	check_indentifier(char *indent, t_tracer *rt)
{
	rt->parsing_type = 0;
	if (ft_strcmp(indent, AMBIENT))
		rt->parsing_type = 1;
	else if (ft_strcmp(indent, CAMERA))
		rt->parsing_type = 2;
	else if (ft_strcmp(indent, LIGHT))
		rt->parsing_type = 3;
	else if (ft_strcmp(indent, SPHERE))
		rt->parsing_type = 4;
	else if (ft_strcmp(indent, PLANE))
		rt->parsing_type = 5;
	else if (ft_strcmp(indent, CYLINDER))
		rt->parsing_type = 6;
	return (rt->parsing_type);
}

int	fill_struct(char **split, t_tracer *rt)
{
	if (rt->parsing_type == 1)
		return (fill_ambient(split + 1, rt));
	else if (rt->parsing_type == 2)
		return (fill_camera(split + 1, rt));
	else if (rt->parsing_type == 3)
		return (fill_light(split + 1, rt));
	else if (rt->parsing_type == 4)
		// return (fill_sphere(split, rt));
		return (fill_sphere(split + 1, rt));
	else if (rt->parsing_type == 5)
		return (fill_plane(split + 1, rt));
	else if (rt->parsing_type == 6)
		return (fill_cylinder(split + 1, rt));
	// return (1);
	return (0); // or 1?
}
