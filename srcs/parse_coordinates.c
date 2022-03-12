#include "../includes/mini_RT.h"

int	check_xyz_line(char *xyz)
{
	int				i;
	unsigned char	dot;

	dot = 1;
	i = 0;
	if (xyz[i] == '-')
		i++;
	while (xyz[i])
	{
		if (xyz[i] == '.' && dot)
		{
			dot--;
			i++;
		}
		if (xyz[i] && !ft_isdigit(xyz[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_xyz(char **xyz)
{
	int	j;

	j = 0;
	while(xyz[j])
	{
		if (!check_xyz_line(xyz[j]))
			return (0);
		j++;
	}
	return (j == 3);
}

int	stop_parse(char **xyz)
{
	int	i;

	if (xyz)
	{
		i = 0;
		while (xyz[i])
		{
			free(xyz[i]);
			i++;
		}
		free(xyz);
	}
	return (0);
}

void	find_struct(t_coord coord, t_tracer *rt)
{
	if (rt->parsing_type == 2)
		rt->camera->xyz = coord;
	if (rt->parsing_type == 3)
		rt->light->xyz = coord;
	if (rt->parsing_type == 4)
		rt->sphere->xyz = coord;
	if (rt->parsing_type == 5)
		rt->plane->xyz = coord;
	if (rt->parsing_type == 6)
		rt->cyl->xyz = coord;
}

int	parse_coordinates(char **split, t_tracer *rt)
{
	t_coord	coord;
	char	**xyz;

	xyz = ft_split(split[0], ',');
	if (!xyz || !check_xyz(xyz))
		return (stop_parse(xyz));
	coord.x = ft_atod(xyz[0]);
	coord.y = ft_atod(xyz[1]);
	coord.z = ft_atod(xyz[2]);
	if (xyz[3])
		return (stop_parse(xyz));
	find_struct(coord, rt);
	return (1);
}