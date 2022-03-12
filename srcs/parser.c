#include "../includes/mini_RT.h"

int	process_line(t_tracer *rt, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!check_indentifier(split[0], rt))
		return (0);
	if (!fill_struct(++split, rt))
		return (0);
//	printf("%d indentifier\n", rt->parsing_type);
	return (1);
}

int	parse_rt_file(t_tracer *rt, char *path)
{
	int	fd;
	char *line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	for (int i = 0; i < 2; i++)
	{
		get_next_line(fd, &line);
		if (!process_line(rt, line))
			return (0);
	}
	printf("AMBIENT LIGHT\n%d r %d g %d b\n%f bright\n", rt->ambient->color.R,
		   rt->ambient->color.G, rt->ambient->color.B,
		   rt->ambient->bright);
	printf("CAMERA\n%f x %f y %f x XYZ\n%f x %f y %f z VECTOR\n%d FOV\n",
		   rt->camera->xyz.x,
		   rt->camera->xyz.y, rt->camera->xyz.z, rt->camera->vector.x,
		   rt->camera->vector.y, rt->camera->vector.z, rt->camera->FOV);
	close(fd);
	return (1);
}