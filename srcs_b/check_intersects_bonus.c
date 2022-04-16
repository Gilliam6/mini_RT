/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersects_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:35:09 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/16 13:27:30 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/mini_RT_bonus.h"

int	check_intersects(t_tracer *rt, t_coord dir)
{
	rt->solve = 0;
	first_intersect_sphere(rt, dir);
	first_intersect_plane(rt, dir);
	first_intersect_cyl(rt, dir);
	if (!rt->solve)
		return (0);
	return (1);
}
