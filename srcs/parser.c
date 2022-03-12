#include "../includes/mini_RT.h"

int	process_line(t_tracer *rt, char *line)
{
	char	**split;
	char	**tmp;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	tmp = split;
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

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);

	while (get_next_line(fd, &line))
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
	close(fd);
	return (1);
}