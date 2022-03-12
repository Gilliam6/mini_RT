#include "../includes/mini_RT.h"

int	process_line(t_tracer *rt, char *line)
{
	char	**split;
	char	**tmp;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	tmp = split;
	if (!split[0])
		return (-1);
	if (!check_indentifier(tmp[0], rt))
		return (0);
	if (!fill_struct(++tmp, rt))
		return (0);
	return (!stop_parse(split));
}

int	parse_rt_file(t_tracer *rt, char *path)
{
	int	fd;
	char *line;
	int i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);

	while (get_next_line(fd, &line))
	{
		i = process_line(rt, line);
		if (i < 0)
			continue;
		if (!i)
			return (0);
	}
	if (!process_line(rt, line))
		return (0);
	printf("AMBIENT LIGHT\n%d r %d g %d b\n%f bright\n", rt->ambient->color.R,
		   rt->ambient->color.G, rt->ambient->color.B,
		   rt->ambient->bright);
	printf("CAMERA\n%f x %f y %f x XYZ\n%f x %f y %f z VECTOR\n%d FOV\n",
		   rt->camera->xyz.x,
		   rt->camera->xyz.y, rt->camera->xyz.z, rt->camera->vector.x,
		   rt->camera->vector.y, rt->camera->vector.z, rt->camera->FOV);
	printf("LIGHT\n%d r %d g %d b COLOR\n%f BRIGHT\n%f x %f y %f z XYZ\n",
		   rt->light->color.R,
		   rt->light->color.G, rt->light->color.B,
		   rt->light->bright, rt->light->xyz.x,rt->light->xyz.y,
		   rt->light->xyz.z);
	printf("SPHERE\n%d r %d g %d b COLOR\n%f DIAMETER\n%f x %f y %f z XYZ\n",
		   rt->sphere->color.R,
		   rt->sphere->color.G, rt->sphere->color.B,
		   rt->sphere->diameter, rt->sphere->xyz.x,rt->sphere->xyz.y,
		   rt->sphere->xyz.z);
	printf("PLANE\n%d r %d g %d b COLOR\n%f x %f y %f z VECTOR\n%f x %f y %f"
		   " z XYZ\n",
		   rt->plane->color.R,
		   rt->plane->color.G, rt->plane->color.B,
		   rt->plane->vector.x, rt->plane->vector.y,rt->plane->vector.z,
		   rt->plane->xyz.x,rt->plane->xyz.y,
		   rt->plane->xyz.z);
	printf("CYLINDER\n%d r %d g %d b COLOR\n%f DIAMETER\n%f x %f y %f z "
		   "XYZ\n%f HEIGHT\n%f x %f y %f z VECTOR\n",
		   rt->cyl->color.R,
		   rt->cyl->color.G, rt->cyl->color.B,
		   rt->cyl->diameter, rt->cyl->xyz.x,rt->cyl->xyz.y,
		   rt->cyl->xyz.z, rt->cyl->height, rt->cyl->vector.x,
		   rt->cyl->vector.y,
		   rt->cyl->vector.z);
	close(fd);
	return (1);
}