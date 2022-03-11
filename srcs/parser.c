#include "../includes/mini_RT.h"

int	parse_rt_file(t_tracer *rt, char *path)
{
	int	fd;
	char *line;
	(void)rt;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return (1);
}