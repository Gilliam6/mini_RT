/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:41:40 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:41:43 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

double	plaintersect(t_coord cam, t_coord dir, t_plane *plane)
{
	double	x;
	double	denom;

	denom = scalar_product(plane->vector, dir);
	if (denom == 0)
		return (-1.0);
//	x = (dot(plane_nv, vsubstract(plane_p, o))) / denom;
	x = (scalar_product(plane->vector, \
		vector_sub(plane->xyz, cam))) / denom;
	if (x > 0)
		return (x);
	else
		return (-1.0);
}

void	first_intersect_plane(t_tracer *rt, t_coord dir)
{
	t_plane	*start;
	double solve;

	start = rt->plane;
	while (start)
	{
		solve = plaintersect(rt->camera->xyz, dir, start);
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
