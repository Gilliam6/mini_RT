/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:35:09 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 18:08:18 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	check_intersects(t_tracer *rt, t_coord dir)
{
	if (!first_intersect_sphere(rt, dir) && !first_intersect_plane(rt, dir)
		&& !first_intersect_cyl(rt, dir))
		return (0);
	return (1);
}
