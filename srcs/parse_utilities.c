#include "../includes/mini_RT.h"

int	check_colors(t_color color)
{
	if (color.R < 0 || color.R > 255)
		return (0);
	if (color.G < 0 || color.G > 255)
		return (0);
	if (color.B < 0 || color.B > 255)
		return (0);
	return (1);
}

t_color	parse_colors(char **split, t_tracer *rt)
{
	char		**rgb;
	t_color 	color;

	rgb = ft_split(split[0], ',');
	color.R = ft_atoi(rgb[0]);
	color.G = ft_atoi(rgb[1]);
	color.B = ft_atoi(rgb[2]);
	if (rgb[3] || !check_colors(color))
		return (0);
	return (color);
}

double	ft_atod(char *str)
{
	double	result;
	int		del;
	int 	minus;

	result = 0;
	if (*str == '-')
		minus = -1;
	while (*str && *str != '.')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str != '.')
		unexpected_exit(PARSE_ERR);
	del = 10;
	while (*str)
	{
		result += (*str - '0') / del;
		del *= 10;
		str++;
	}

}
double	parse_bright(char **split, t_tracer *rt)
{
	ft_atod(split[0])
}
