/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:36:53 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:28:10 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	check_diameter(double diameter)
{
	if (diameter <= 0)
		return (0);
	return (1);
}

int	fill_sphere(char **split, t_tracer *rt)
{
	t_sphere	*sphere;

	if (!split[0] || check_double_in_arr(split[0]) == -1 || \
	!split[1] || check_double(split[1], 0) == -1 || \
	!split[2] || check_ints(split[2]) == -1 || split[3])
	{
		printf("Some problem in map with sphere\n");
		return (0);
	}
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	add_sphere_back(&rt->sphere, sphere);
	if (!parse_coordinates(split++, rt, sphere))
		return (0);
	sphere->diameter = ft_atod(*split++);
	sphere->color = parse_colors(split++);
	if (!check_diameter(sphere->diameter) || sphere->color.r == -1 || split[0])
	{
		printf("Some problem in map with sphere\n");
		return (0);
	}
	return (1);
}

int	fill_plane(char **split, t_tracer *rt)
{
	t_plane	*plane;

	if (!split[0] || check_double_in_arr(split[0]) == -1 || \
	!split[1] || check_double_in_arr(split[1]) == -1 || \
	!split[2] || check_ints(split[2]) == -1 || split[3])
	{
		printf("Some problem in map with plane\n");
		return (0);
	}
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (0);
	add_plane_back(&rt->plane, plane);
	if (!parse_coordinates(split++, rt, plane) || \
	!parse_vector(split++, rt, plane))
	{
		printf("Some problem in map with plane\n");
		return (0);
	}
	plane->color = parse_colors(split++);
	if (plane->color.r == -1)
		return (0);
	return (1);
}

int	fill_cylinder(char **split, t_tracer *rt)
{
	t_cylinder	*cyl;

	if (!split[0] || check_double_in_arr(split[0]) == -1 || \
	!split[1] || check_double_in_arr(split[1]) == -1 || \
	!split[2] || check_double(split[2], 0) || \
	!split[3] || check_double(split[3], 0) || \
	!split[4] || check_ints(split[4]) == -1 || split[5])
		return (0);
	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		return (0);
	add_cylinder_back(&rt->cyl, cyl);
	if (!parse_coordinates(split++, rt, cyl) || !parse_vector(split++, rt, cyl))
		return (0);
	if (*split)
		cyl->diameter = ft_atod(*split++);
	if (*split)
		cyl->height = ft_atod(*split++);
	if (*split)
		cyl->color = parse_colors(split++);
	if (!check_diameter(cyl->diameter) || \
	!check_diameter(cyl->height) || \
	cyl->color.r == -1 || split[0])
		return (0);
	return (1);
}
