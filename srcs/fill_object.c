#include "../includes/mini_RT.h"

int	check_diameter(double diameter)
{
	if (diameter <= 0)
		return (0);
	return (1);
}

int	fill_sphere(char **split, t_tracer *rt)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(sphere));
	if (!sphere)
		return (0);
	rt->sphere = sphere;
	if (!parse_coordinates(split++, rt))
		return (0);
	sphere->diameter = ft_atod(*split++);
	sphere->color = parse_colors(split++);
	if (!check_diameter(sphere->diameter) || sphere->color.R == -1 || split[0])
		return (0);
	return (1);
}
