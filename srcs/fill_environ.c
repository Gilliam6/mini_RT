/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:39:21 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:28:27 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	fill_ambient(char **split, t_tracer *rt)
{
	t_ambient	*amb;

	if (rt->ambient)
		return (0);
	amb = malloc(sizeof(t_ambient));
	if (!amb)
		return (0);
	rt->ambient = amb;
	if (!split[0] || check_double(split[0], 0) == -1 || \
	!split[1] || check_ints(split[1]) == -1 || split[2])
			amb->bright = -1.0;
	else
	{
		amb->bright = parse_bright(split++);
		amb->color = parse_colors(split++);
	}
	if (amb->bright < 0 || amb->color.r == -1)
	{
		printf("Some problem in map with amb. light\n");
		return (0);
	}
	return (*split == 0);
}

int	fill_camera(char **split, t_tracer *rt)
{
	t_camera	*cam;

	if (rt->camera)
		return (0);
	if (!split[0] || check_double_in_arr(split[0]) == -1 || \
	!split[1] || check_double_in_arr(split[1]) == -1 || \
	!split[2] || check_ony_one_int(split[2]) == -1 || split[3])
	{
		printf("Some problem in map with camera\n");
		return (0);
	}
	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (0);
	rt->camera = cam;
	if (!parse_coordinates(split++, rt, cam) || \
		!parse_vector(split++, rt, cam) || \
		!parse_fov(split++, rt) || split[0])
	{
		printf("Some problem in map with camera\n");
		return (0);
	}
	return (1);
}

int	fill_light(char **split, t_tracer *rt)
{
	t_light	*light;

	if (rt->light)
		return (0);
	if (!split[0] || check_double_in_arr(split[0]) == -1 || \
	!split[1] || check_double(split[1], 0) == -1 || \
	!split[2] || check_ints(split[2]) == -1 || split[3])
	{
		printf("Some problem in map with light\n");
		return (0);
	}
	light = malloc(sizeof(t_light));
	if (!light)
		return (0);
	rt->light = light;
	if (!parse_coordinates(split++, rt, light))
		return (0);
	light->bright = parse_bright(split++);
	light->color = parse_colors(split++);
	if (light->bright < 0 || light->color.r == -1)
	{
		printf("Some problem in map with light\n");
		return (0);
	}
	return (1);
}
