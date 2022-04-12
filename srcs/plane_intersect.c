#include "../includes/mini_RT.h"

double	plaIntersect(t_coord cam, t_coord dir, t_plane *plane)
{
	double	x;
	double	denom;

	denom = scalar_product(plane->vector, dir);
	if (denom == 0)
		return (-1.0);
//	x = (dot(plane_nv, vsubstract(plane_p, o))) / denom;
	x = (scalar_product(plane->vector, vector_sub
	(plane->xyz, cam))) / denom;
	if (x > 0)
		return (x);
	else
		return (-1.0);
}

int first_intersect_plane(t_tracer *rt, t_coord dir)
{
	double tmp;
	t_plane *start;

	start = rt->plane;
	while (start)
	{
		tmp = plaIntersect(rt->camera->xyz, dir, start);
		if ((!rt->solve && tmp > 0) || (tmp < rt->solve && tmp > EPSILON))
		{
			rt->solve = tmp;
			rt->final_color = init_vector_from_rgb(start->color);
			rt->final_coord = start->xyz;
		}
		start = start->next;
	}
	if (!rt->solve)
	{
//		write(1, "hi\n", 3);
		rt->solve = 0;
		rt->final_color = init_vector(0,0,0);
		return (0);
	}
	return (1);
}
