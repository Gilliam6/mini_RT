/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:32:46 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:39:10 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

t_coord	pa(t_cylinder *cyl)
{
	t_coord	pa;

	pa = vector_add(cyl->xyz, vector_pow_value(cyl->vector, \
		cyl->height / 2));
	return (pa);
}

t_coord	pb(t_cylinder *cyl)
{
	t_coord	pb;

	pb = vector_sub(cyl->xyz, vector_pow_value(cyl->vector, \
		cyl->height / 2));
	return (pb);
}

t_vec4	init_vec4(double x, double y, double z, double w)
{
	t_vec4	fin;

	fin.x = x;
	fin.y = y;
	fin.z = z;
	fin.w = w;
	return (fin);
}

t_sphere_calc	what_is_h(t_coord cam, t_coord dir, t_coord pa, \
		t_coord pb, double r)
{
	t_sphere_calc	final;

	final.ca = vector_sub(pb, pa);
	final.oc = vector_sub(cam, pa);
	final.caca = scalar_product(final.ca, final.ca);
	final.card = scalar_product(final.ca, dir);
	final.caoc = scalar_product(final.ca, final.oc);
	final.a = final.caca - final.card * final.card;
	final.b = final.caca * scalar_product(final.oc, dir) \
		- final.caoc * final.card;
	final.c = final.caca * scalar_product(final.oc, \
		final.oc) - final.caoc * final.caoc - r * r * final.caca;
	final.h = final.b * final.b - final.a * final.c;
	return (final);
}

t_vec4	cylintersect(t_coord cam, t_coord dir, t_coord pa, t_coord pb, double r)
{
	t_sphere_calc	final;

	final = what_is_h(cam, dir, pa, pb, r);
	if (final.h < 0)
		return (init_vec4(-1.0, -1.0, -1.0, -1.0));
	final.h = sqrt(final.h);
	final.t = (-final.b - final.h) / final.a;
	final.y = final.caoc + final.t * final.card;
	final.xyz = vector_del_value(vector_sub \
		(vector_add(final.oc, vector_pow_value \
		(dir, final.t)), vector_del_value(vector_pow_value \
		(final.ca, final.y), final.caca)), r);
	if (final.y > 0.0 && final.y < final.caca)
		return (init_vec4(final.xyz.x, final.xyz.y, final.xyz.z, final.t));
	if (final.y < 0.0)
		final.y = 0.0;
	else
		final.y = final.caca;
	final.t = final.y - final.caoc / final.card;
	final.xyz = vector_pow_value(final.ca, sin(final.y) / final.caca);
	if (fabs(final.b + final.a * final.t) < final.h)
		return (init_vec4(final.xyz.x, final.xyz.y, final.xyz.z, final.t));
	else
		return (init_vec4(-1.0, -1.0, -1.0, -1.0));
}

double min_tmp(t_vec4 tmp)
{
	double final = tmp.x;
	if (tmp.z > EPSILON && final < tmp.z)
		final = tmp.z;
	if (tmp.y > EPSILON && final < tmp.y)
		final = tmp.y;
	if (tmp.w > EPSILON && final < tmp.w)
		final = tmp.w;
	return (final);
}

void	first_intersect_cyl(t_tracer *rt, t_coord dir)
{
	t_vec4		tmp;
	t_cylinder	*start;
	double		solve;

	start = rt->cyl;
	while (start)
	{
		tmp = cylintersect(rt->camera->xyz, dir, pb(start),
			pa(start), start->diameter / 2.0);
		solve = min_tmp(tmp);
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
