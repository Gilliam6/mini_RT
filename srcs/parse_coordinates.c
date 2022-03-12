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

int	stop_parse_coord(char **xyz)
{
	if (xyz)
		free(xyz);
	return (0);
}

int	parse_coordinates(char **split, t_tracer *rt)
{
	t_coord	coord;
	char	**xyz;
	(void) rt;
	xyz = ft_split(split[0], ',');
	if (!xyz || !check_xyz(xyz))
		return (stop_parse_coord(xyz));
	coord.x = ft_atod(xyz[0]);
	coord.y = ft_atod(xyz[1]);
	coord.z = ft_atod(xyz[2]);
	if (xyz[3])
		return (stop_parse_coord(xyz));
	rt->camera->xyz = coord;
	return (1);
}