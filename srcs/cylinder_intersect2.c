/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:32:46 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/15 19:20:28 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

double	min_tmp(t_vec4 tmp)
{
	double	final;

	final = tmp.x;
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
	t_papb		papb;

	start = rt->cyl;
	while (start)
	{
		papb.pa = pa(start);
		papb.pb = pb(start);
		tmp = cylintersect(rt->camera->xyz, dir, papb, start->diameter / 2.0);
		solve = min_tmp(tmp);
		if ((!rt->solve && solve > EPSILON) || (solve < rt->solve && \
			solve > EPSILON))
		{
			rt->solve = solve;
			rt->final_color = init_vector_from_rgb(start->color);
			rt->final_coord = start->xyz;
		}
		start = start->next;
	}
}
