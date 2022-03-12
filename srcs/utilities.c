#include "../includes/mini_RT.h"

double	ft_atod(char *str)
{
	double	result;
	double	del;
	double 	minus;

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
