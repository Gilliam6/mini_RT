/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:22:19 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/07 19:23:54 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

t_vec2	ray_intersect( t_coord cam, t_coord dir, t_coord sphere, double radius )
{
	t_vec2	res;
	t_coord	oc;

	oc = vector_sub(cam, sphere);
	double b = scalar_product(oc, dir);
	double c = scalar_product(oc, oc) - (radius * radius);
	double h = b * b - c;

	if (h < 0.0)
	{
		res.x = -1;
		res.y = -1;
		return (res);
	} // no intersection
	h = sqrt(h);
	res.x = -b - h;
	res.y = -b + h;
	return (res);
}

int	first_intersect_sphere(t_tracer *rt, t_coord dir)
{
	t_vec2		tmp;
	t_sphere	*final;
	t_sphere	*start;

	rt->solve.x = 0;
	rt->solve.y = 0;
	start = rt->sphere;
	while (start)
	{
		tmp = ray_intersect(rt->camera->xyz, dir, \
			start->xyz, start->diameter / 2.0);
		if ((!rt->solve.x && tmp.x > 0) || \
			(tmp.x < rt->solve.x && tmp.x > EPSILON))
		{
			rt->solve = tmp;
			rt->final_color = init_vector_from_rgb(start->color);
			rt->final_coord = start->xyz;
			final = start;
		}
		start = start->next;
	}
	if (!rt->solve.x)
	{
		rt->solve.x = -1.0;
		rt->final_color = init_vector(0,0,0);
		return (0);
	}
	return (1);
}
