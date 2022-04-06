/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:43:33 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/06 18:47:31 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (xyz[j])
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

void	find_struct_xyz(t_coord coord, t_tracer *rt, void *ptr)
{
	t_plane		*copy_pl;
	t_cylinder	*copy_cyl;
	t_sphere	*copy_sp;

	if (rt->parsing_type == 2)
		rt->camera->xyz = coord;
	else if (rt->parsing_type == 3)
		rt->light->xyz = coord;
	else if (rt->parsing_type == 4)
	{
		copy_sp = (t_sphere *)ptr;
		copy_sp->xyz = coord;
	}
	else if (rt->parsing_type == 5)
	{
		copy_pl = (t_plane *)ptr;
		copy_pl->xyz = coord;
	}
	else if (rt->parsing_type == 6)
	{
		copy_cyl = (t_cylinder *)ptr;
		copy_cyl->xyz = coord;
	}
}

int	parse_coordinates(char **split, t_tracer *rt, void *ptr)
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
	{
		stop_parse(xyz);
		return (stop_parse(xyz));
	}
	stop_parse(xyz);
	find_struct_xyz(coord, rt, ptr);
	return (1);
}
