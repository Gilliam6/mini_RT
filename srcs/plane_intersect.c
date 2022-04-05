#include "../includes/mini_RT.h"

double	plaIntersect(t_coord cam, t_coord dir, t_plane *plane)
{
	double	denom;
	double	res;
	t_coord xyz_norm;

	xyz_norm = normalize(plane->xyz);
	denom = scalar_product(xyz_norm, dir);
	if (fabs(denom) > 0.001)
	{
		res = scalar_product(vector_sub(plane->xyz, cam),xyz_norm) / denom;
		if (res >= 0)
			return (res);
	}
	return (-1.0);
//	return -(dot(ro,p.xyz)+p.w)/dot(rd,p.xyz);
}

t_coord first_intersect_plane(t_tracer *rt, t_coord dir)
{
	double tmp;
	t_plane *final;
	t_plane *start;

	start = rt->plane;
	while (start)
	{
		tmp = plaIntersect(rt->camera->xyz, dir, start);
		if (!rt->solve.x && tmp > 0)
		{
			rt->solve.x = tmp;
			final = start;
		}
		else if (tmp < rt->solve.x && tmp > 0)
		{
			rt->solve.x = tmp;
			final = start;
		}
		start = start->next;
	}
	return (final->xyz);
}
