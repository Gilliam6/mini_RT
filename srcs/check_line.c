#include "../includes/mini_RT.h"

int	check_indentifier(char *indent, t_tracer *rt)
{
	rt->parsing_type = 0;
	if (ft_strcmp(indent, AMBIENT))
		rt->parsing_type = 1;
	else if (ft_strcmp(indent, CAMERA))
		rt->parsing_type = 2;
	else if (ft_strcmp(indent, LIGHT))
		rt->parsing_type = 3;
	else if (ft_strcmp(indent, SPHERE))
		rt->parsing_type = 4;
	else if (ft_strcmp(indent, PLANE))
		rt->parsing_type = 5;
	else if (ft_strcmp(indent, CYLINDER))
		rt->parsing_type = 6;
	return (rt->parsing_type);
}
