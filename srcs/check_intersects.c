#include "../includes/mini_RT.h"

int	check_intersects(t_tracer *rt, t_coord dir)
{
	if (!first_intersect_sphere(rt, dir) && !first_intersect_plane(rt, dir)
	&& !first_intersect_cyl(rt, dir))
		return (0);
	return (1);
}