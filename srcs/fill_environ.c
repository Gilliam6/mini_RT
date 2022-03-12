#include "../includes/mini_RT.h"

int	fill_ambient(char **split, t_tracer *rt)
{
	t_ambient	*amb;

	amb = malloc(sizeof(t_tracer));
	if (!amb)
		return (0);
	amb->bright = parse_bright(split++);
	amb->color = parse_colors(split++);
	if (amb->bright < 0 || amb->color.R == -1)
	{
		free(amb);
		return (0);
	}
	else
		rt->ambient = amb;
	return (*split == 0);
}

int	fill_camera(char **split, t_tracer *rt)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (0);
	rt->camera = cam;
	if (!parse_coordinates(split++, rt) || !parse_vector(split++, rt))
		return (0);
	return (1);
}