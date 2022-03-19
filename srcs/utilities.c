#include "../includes/mini_RT.h"

int	check_ints(char *str) // only int and commas
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			++counter;
		if (!isdigit(str[i]) && !(str[i] == ',' && str[i + 1] && i != 0))
		{
			printf("error in str[i] = %c\n", str[i]);
			return (-1);
		}
	}
	if (counter != 2)
		{
			printf("invalid comma in str[i] = %c\n", str[i]);
			return (-1);
		}
	return (0);
}

int	check_ony_one_int(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!isdigit(str[i]))
		{
			printf("error in str[i] = %c\n", str[i]);
			return (-1);
		}
	}
	return (0);
}

double	check_double_in_arr(char *str) // only commas, points and digits
{
	int	i;

	i = -1;
	// printf("double in str: %s\n", str);
	while (str[++i])
	{
		if (str[0] == '-')
			++i;
		if (!isdigit(str[i]) && str[i] != ',' && \
		!(str[i] == '.' && i != 0))
		{
			// printf("atod: wrong str = %c\n", str[i]);
			return (-1.0);
		}
	}
	return (0);
}

double	check_double(char *str) // only digit and point
{
	int	i;

	i = -1;
	// printf("double in str: %s\n", str);
	while (str[++i])
	{
		if (!isdigit(str[i]) && !(str[i] == '.' && i != 0))
		{
			// printf("atod: wrong str = %c\n", str[i]);
			return (-1.0);
		}
	}
	return (0);
}

double	ft_atod(char *str)
{
	double	result;
	double	del;
	double 	minus;

	result = 0.0;
	minus = 1.0;
	if (*str == '-' && *str++)
	// if ((*str == '-' && *str++) || check_num(str) == -1)
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
