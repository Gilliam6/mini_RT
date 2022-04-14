/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utilities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:49:44 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:30:36 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

double	scalar_product(t_coord v1, t_coord v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	magnitude(t_coord v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
}

t_coord	normalize(t_coord v1)
{
	return (vector_pow_value(v1, 1 / magnitude(v1)));
}
