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
		return (-1 + stop_parse(split)); ///check malloc????
	if (!check_indentifier(tmp[0], rt))
	{
		printf("invalid type ID\n");
		return (0 + stop_parse(split));
	}
	if (!fill_struct(++tmp, rt)) // может, здесь нужен цикл?
	{
		printf("fill_struct = 0\n"); //del
		return (0 + stop_parse(split));
		// return (0);
	}
	return (!stop_parse(split));
}

void	print_amb(t_tracer *rt) //del?
{
	printf("AMBIENT LIGHT\n%d r %d g %d b\n%f bright\n", rt->ambient->color.R,
	rt->ambient->color.G, rt->ambient->color.B,
	rt->ambient->bright);
}

void	print_cam(t_tracer *rt) //del?
{
	printf("CAMERA\n%f x %f y %f x XYZ\n%f x %f y %f z VECTOR\n%d FOV\n",
	rt->camera->xyz.x,
	rt->camera->xyz.y, rt->camera->xyz.z, rt->camera->vector.x,
	rt->camera->vector.y, rt->camera->vector.z, rt->camera->FOV);
}
void	print_light(t_tracer *rt) //del?
{
	printf("LIGHT\n%d r %d g %d b COLOR\n%f BRIGHT\n%f x %f y %f z XYZ\n",
		rt->light->color.R,
		rt->light->color.G, rt->light->color.B,
		rt->light->bright, rt->light->xyz.x,rt->light->xyz.y,
		rt->light->xyz.z);
}
void	print_sphere(t_tracer *rt) //del?
{
	t_sphere *copy = rt->sphere;
	int i = 0;
	printf("\nSPHERES:\n");
	while (copy)
	{
		printf("N %d:	\n%d r %d g %d b COLOR\n%f DIAMETER\n%f x %f y %f z XYZ\n",
		++i,
		copy->color.R,
		copy->color.G, copy->color.B,
		copy->diameter, copy->xyz.x,copy->xyz.y,
		copy->xyz.z);
		copy = copy->next;
	}
}

void	print_plane(t_tracer *rt) //del?
{
	t_plane *copy = rt->plane;
	int i = 0;
	printf("\nPLANES:\n");
	while (copy)
	{
	printf("N %d:	\n%d r %d g %d b COLOR\n%f x %f y %f z VECTOR\n%f x %f y %f"
		" z XYZ\n",
		++i,
		copy->color.R,
		copy->color.G, copy->color.B,
		copy->vector.x, copy->vector.y,copy->vector.z,
		copy->xyz.x,copy->xyz.y,
		copy->xyz.z);
		copy = copy->next;
	}
}
void	print_cyl(t_tracer *rt) //del?
{
	t_cylinder *copy = rt->cyl;
	int i = 0;
	printf("\nCYLINDERS:\n");
	while (copy)
	{
	printf("N %d:	\n%d r %d g %d b COLOR\n%f DIAMETER\n%f x %f y %f z "
		"XYZ\n%f HEIGHT\n%f x %f y %f z VECTOR\n",
		++i,
		copy->color.R,
		copy->color.G, copy->color.B,
		copy->diameter, copy->xyz.x,copy->xyz.y,
		copy->xyz.z, copy->height, copy->vector.x,
		copy->vector.y,
		copy->vector.z);
	copy = copy->next;
	}
}

int	check_path(char *path)
{
	int	len;

	len = 0;
	if (!path)
		return (1);
	while (path[len] != 0)
		len++;
	if (len < 3 || path[len - 1] != 't' || \
	path[len - 2] != 'r' || path[len - 3] != '.')
	{
		printf("Wrong map's name\n");
		return (1);
	}
	return (0);
}

int	parse_rt_file(t_tracer *rt, char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0 || check_path(path))
		return (0);
	while (get_next_line(fd, &line))
	{
		// printf("line from GNL = %s\n", line);
		i = process_line(rt, line);
		free(line); //???
		if (i < 0)
		{
			printf("find empty str\n");
			continue;
		}
		if (!i)
			return (0);
	}
	i = process_line(rt, line);
	free(line); //???
	if (!i)
		return (0);
	print_amb(rt); //del?
	print_cam(rt); //del?
	print_light(rt); //del?
	print_sphere(rt); //del?
	print_plane(rt); //del?
	print_cyl(rt); //del?
	close(fd);
	return (1);
}