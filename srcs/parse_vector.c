/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:44:40 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/06 18:44:43 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	check_vector(t_coord coord)
{
	if (coord.x < -1.0 || coord.x > 1.0)
		return (0);
	if (coord.y < -1.0 || coord.y > 1.0)
		return (0);
	if (coord.z < -1.0 || coord.z > 1.0)
		return (0);
	return (1);
}

void	find_struct_vector(t_coord coord, t_tracer *rt, void *ptr)
{
	t_plane		*copy_pl;
	t_cylinder	*copy_cyl;

	if (rt->parsing_type == 2)
		rt->camera->vector = coord;
	else if (rt->parsing_type == 5)
	{
		copy_pl = (t_plane *)ptr;
		copy_pl->vector = coord;
	}
	else if (rt->parsing_type == 6)
	{
		copy_cyl = (t_cylinder *)ptr;
		copy_cyl->vector = coord;
	}
}

int	parse_vector(char **split, t_tracer *rt, void *ptr)
{
	t_coord	coord;
	char	**vector;

	vector = ft_split(split[0], ',');
	if (!vector || !check_xyz(vector))
		return (stop_parse(vector));
	coord.x = ft_atod(vector[0]);
	coord.y = ft_atod(vector[1]);
	coord.z = ft_atod(vector[2]);
	if (vector[3] || !check_vector(coord))
		return (stop_parse(vector));
	find_struct_vector(coord, rt, ptr);
	return (!stop_parse(vector));
}
