#include "../includes/mini_RT.h"

double	parse_bright(char **split)
{
	double	bright;

	bright = ft_atod(split[0]);
	// free(split[0]);
	if (bright < 0.0 || bright > 1.0)
		return (-1.0);
	return (bright);
}
