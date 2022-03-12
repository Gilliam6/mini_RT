#include "../includes/mini_RT.h"

int	parse_fov(char **split, t_tracer *rt)
{
	int	fov;

	fov = ft_atod(split[0]);
	if (fov < 0 || fov > 180)
		return (0);
	rt->camera->FOV = fov;
	return (1);
}

