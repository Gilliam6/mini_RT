/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:49:27 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:31:05 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

t_coord	vector_sub(t_coord vec1, t_coord vec2)
{
	t_coord	res;

	res.x = vec1.x - vec2.x;
	res.y = vec1.y - vec2.y;
	res.z = vec1.z - vec2.z;
	return (res);
}

t_coord	vector_sub_val(t_coord vec1, double vec2)
{
	t_coord	res;

	res.x = vec1.x - vec2;
	res.y = vec1.y - vec2;
	res.z = vec1.z - vec2;
	return (res);
}

t_coord	vector_pow(t_coord vec1, t_coord vec2)
{
	t_coord	res;

	res.x = vec1.x * vec2.x;
	res.y = vec1.y * vec2.y;
	res.z = vec1.z * vec2.z;
	return (res);
}

t_coord	vector_add(t_coord vec1, t_coord vec2)
{
	t_coord	res;

	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;
	return (res);
}

t_coord	vector_add_val(t_coord vec1, double vec2)
{
	t_coord	res;

	res.x = vec1.x + vec2;
	res.y = vec1.y + vec2;
	res.z = vec1.z + vec2;
	return (res);
}
