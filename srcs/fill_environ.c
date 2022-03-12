#include "../includes/mini_RT.h"

int	fill_ambient(char **split, t_tracer *rt)
{
	t_ambient	*amb;

	amb = malloc(sizeof(t_tracer));
	amb->bright = parse_bright(split++);
	amb->color = parse_colors(split++);
	if (amb->bright < 0 || amb->color.R == -1)
	{
		free(amb);
		return (0);
	}
	else
		rt->ambient = amb;
	return (*split == 0);
}
