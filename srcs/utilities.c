#include "../includes/mini_RT.h"

double	ft_atod(char *str)
{
	double	result;
	double	del;
	double	minus;

	result = 0.0;
	minus = 1.0;
	if (*str == '-' && *str++)
		minus = -1.0;
	while (*str && *str != '.')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str == '.')
		str++;
	del = 1;
	while (*str)
	{
		del *= 10;
		result += (*str - '0') / del;
		str++;
	}
	return (minus * result);
}

static int	check_path(char *path)
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

int	check_argv(char *path)
{
	int			fd;
	char		test;

	fd = open(path, O_RDONLY);
	if (fd < 0 || check_path(path))
		return (1);
	if (read(fd, &test, 1) != 1)
	{
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}