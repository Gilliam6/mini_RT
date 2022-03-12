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

t_color	parse_colors(char **split)
{
	char		**rgb;
	t_color 	color;

	rgb = ft_split(split[0], ',');
	color.R = ft_atoi(rgb[0]);
	color.G = ft_atoi(rgb[1]);
	color.B = ft_atoi(rgb[2]);
	if (rgb[3] || !check_colors(color))
	{
		color.R = -1;
		color.B = -1;
		color.G = -1;
	}
	return (color);
}

double	ft_atod(char *str)
{
	double	result;
	double	del;
	double 	minus;

	result = 0.0;
	minus = 1.0;
	if (*str == '-')
		minus = -1.0;
	while (*str && *str != '.')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str != '.' || !*++str)
		unexpected_exit(PARSE_ERR);
	del = 1;
	while (*str)
	{
		del *= 10;
		result += (*str - '0') / del;
		str++;
	}
	return (minus * result);
}

double	parse_bright(char **split)
{
	double	bright;

	bright = ft_atod(split[0]);
	if (bright < 0.0 || bright > 1.0)
		unexpected_exit(PARSE_ERR);
	return (bright);
}
