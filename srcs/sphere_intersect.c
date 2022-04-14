/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:48:25 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:45:21 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

t_vec2	ray_intersect( t_coord cam, t_coord dir, t_coord sphere, double radius )
{
	t_vec2	res;
	t_coord	oc;
	double	b;
	double	c;
	double	h;

	oc = vector_sub(cam, sphere);
	b = scalar_product(oc, dir);
	c = scalar_product(oc, oc) - (radius * radius);
	h = b * b - c;
	if (h < 0.0)
	{
		res.x = -1;
		res.y = -1;
		return (res);
	}
	h = sqrt(h);
	res.x = -b - h;
	res.y = -b + h;
	return (res);
}

void	first_intersect_sphere(t_tracer *rt, t_coord dir)
{
	t_vec2		tmp;
	t_sphere	*start;
	double solve;

	start = rt->sphere;
	while (start)
	{
		tmp = ray_intersect(rt->camera->xyz, dir, start->xyz, start->diameter / 2.0);
		solve = tmp.x;
		if ((!rt->solve && solve > EPSILON) || (solve < rt->solve && solve >
		        EPSILON))
		{
			rt->solve = solve;
			rt->final_color = init_vector_from_rgb(start->color);
			rt->final_coord = start->xyz;
		}
		start = start->next;
	}
}
