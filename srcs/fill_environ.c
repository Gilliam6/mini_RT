#include "../includes/mini_RT.h"

int	fill_ambient(char **split, t_tracer *rt)
{
	rt->ambient->color = parse_colors(split++, rt);
	if (rt->ambient->color)
		return (0);
	rt->ambient->bright = parse_bright(split++, rt);
	if (rt->ambient->bright < 0)
		return (0);
	return (!split);
}
