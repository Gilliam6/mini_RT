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

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	// 	rt->sphere = sphere;
	add_sphere_back(&rt->sphere, sphere);
	if (!parse_coordinates(split++, rt, sphere))
	{
		printf("some problem in argv(sphere)\n");
		return (0);
	}
	sphere->diameter = ft_atod(*split++);
	sphere->color = parse_colors(split++);
	if (!check_diameter(sphere->diameter) || sphere->color.R == -1 || split[0])
	{
		printf("some problem in argv(sphere)\n");
		return (0);
	}
//check:
	// t_sphere	*copy = rt->sphere;
	// int i = 1;
	// while (copy)
	// {
	// 	printf("sphere id = %d: color = %d, diam = %f\n", i, copy->color.R, copy->diameter);
	// 	copy = copy->next;
	// 	++i;
	// }


	return (1);
}

int	fill_plane(char **split, t_tracer *rt)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (0);
	// rt->plane = plane;
	add_plane_back(&rt->plane, plane);
	if (!parse_coordinates(split++, rt, plane) || !parse_vector(split++, rt, plane))
	{
		printf("some problem in argv(plane)\n");
		return (0);
	}
	plane->color = parse_colors(split++);
	if (plane->color.R == -1)
	{
		printf("some problem in argv(plane)\n");
		return (0);
	}

//check:
	// t_plane	*copy = rt->plane;
	// int i = 1;
	// while (copy)
	// {
	// 	printf("plane id = %d: color = %d, vector.x = %f\n", i, copy->color.R, copy->vector.x);
	// 	copy = copy->next;
	// 	++i;
	// }


	return (1);
}

int	fill_cylinder(char **split, t_tracer *rt)
{
	t_cylinder	*cyl;
	// write(1, "hi\n", 3);

	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		return (0);
	// rt->cyl = cyl;
	add_cylinder_back(&rt->cyl, cyl);
	// write(1, "hi\n", 3);
	if (!parse_coordinates(split++, rt, cyl) || !parse_vector(split++, rt, cyl))
	{
		printf("some problem in argv(cylinder)\n");
		return (0);
	}
	if (*split)
		cyl->diameter = ft_atod(*split++);
	if (*split)
		cyl->height = ft_atod(*split++);
	if (*split)
		cyl->color = parse_colors(split++);
	if (!check_diameter(cyl->diameter) || !check_diameter(cyl->height) ||
	cyl->color.R == -1 || split[0])
	{
		printf("some problem in argv(cylinder)\n");
		return (0);
	}

//check:
	// t_cylinder	*copy = rt->cyl;
	// int i = 1;
	// while (copy)
	// {
	// 	printf("t_cylinder id = %d: color = %d, heigt = %f, diam = %f\n", i, copy->color.R, copy->height, copy->diameter);
	// 	copy = copy->next;
	// 	++i;
	// }

	return (1);
}