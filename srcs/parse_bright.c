#include "../includes/mini_RT.h"

double	parse_bright(char **split)
{
	double	bright;

	bright = ft_atod(split[0]);
	if (bright < 0.0 || bright > 1.0)
		unexpected_exit(PARSE_ERR);
	return (bright);
}
