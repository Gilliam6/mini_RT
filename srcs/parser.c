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
	get_next_line(fd, &line);
		if (!process_line(rt, line))
			return (0);
	printf("%d r %d g %d b\n%f bright\n", rt->ambient->color.R,
		   rt->ambient->color.G, rt->ambient->color.B,
		   rt->ambient->bright);
	close(fd);
	return (1);
}