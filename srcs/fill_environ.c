#include "../includes/mini_RT.h"

int	fill_ambient(char **split, t_tracer *rt)
{
	t_ambient	*amb;

	amb = malloc(sizeof(t_tracer));
	if (!amb)
		return (0);
	rt->ambient = amb;
	amb->bright = parse_bright(split++);
	amb->color = parse_colors(split++);
	if (amb->bright < 0 || amb->color.R == -1)
	{
		free(amb);
		return (0);
	}
	return (*split == 0);
}

int	fill_camera(char **split, t_tracer *rt)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (0);
	rt->camera = cam;
	if (!parse_coordinates(split++, rt) || !parse_vector(split++, rt)
	|| !parse_fov(split++, rt) || split[0])
		return (0);
	return (1);
}

int	fill_light(char **split, t_tracer *rt)
{
	t_light	*light;

	light = malloc(sizeof(light));
	if (!light)
		return (0);
	rt->light = light;
	if (!parse_coordinates(split++, rt))
		return (0);
	light->bright = parse_bright(split++);
	light->color = parse_colors(split++);
	if (light->bright < 0 || light->color.R == -1)
	{
		free(light);
		return (0);
	}
	return (1);
}