#include "../includes/mini_RT.h"

int	fill_ambient(char **split, t_tracer *rt)
{
	t_ambient	*amb;

	// amb = malloc(sizeof(t_tracer));
		amb = malloc(sizeof(t_ambient));
	if (!amb)
		return (0);
	rt->ambient = amb;
	if (check_double(split[0]) == -1.0 || check_ints(split[1]) == -1 || split[2])
			amb->bright = -1.0;
	else
	{
		amb->bright = parse_bright(split++);
		amb->color = parse_colors(split++);
	}
	// printf("amb->bright = %f\n", amb->bright);
	// printf("amb->color.R = %d\n", amb->color.R);
	if (amb->bright < 0 || amb->color.R == -1)
	{
		printf("%s\n", RANGE_ERR);
		// free(amb);
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
	if (check_double_in_arr(split[0]) == -1.0 || check_double_in_arr(split[1]) == -1.0 || \
	check_ony_one_int(split[2]) == -1 || split[3])
	{
		printf("%s\n", RANGE_ERR);
		return (0);
	}
	if (!parse_coordinates(split++, rt, cam) || !parse_vector(split++, rt, cam)
	|| !parse_fov(split++, rt) || split[0])
	{
		printf("some problem in argv(camera)\n");
		return (0);
	}
	return (1);
}

int	fill_light(char **split, t_tracer *rt)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (0);
	rt->light = light;
	if (check_double_in_arr(split[0]) == -1.0 || check_double(split[1]) == -1.0 || \
	check_ints(split[2]) == -1 || split[3])
	{
		printf("%s\n", RANGE_ERR);
		return (0);
	}
	if (!parse_coordinates(split++, rt, light))
	{
		printf("some problem in argv(light)\n");
		return (0);
	}
	light->bright = parse_bright(split++);
	light->color = parse_colors(split++);
	if (light->bright < 0 || light->color.R == -1)
	{
		free(light);
		return (0);
	}
	return (1);
}