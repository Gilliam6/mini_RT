/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:16:59 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:29:31 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

void	my_mlx_pixel_put(t_tracer *rt, int x, int y, int color)
{
	char	*dst;

	dst = rt->img.addr + (y * rt->img.line_length + x * \
		(rt->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	colorize(t_color color, double bright)
{
	int	rgb;

	rgb = color.r * bright;
	rgb <<= 8;
	rgb += color.g * bright;
	rgb <<= 8;
	rgb += color.b * bright;
	return (rgb);
}

int	vector_in_color(t_coord vector)
{
	int	rgb;

	rgb = (int)(255 * vector.x);
	rgb <<= 8;
	rgb += (int)(255 * vector.y);
	rgb <<= 8;
	rgb += (int)(255 * vector.z);
	return (rgb);
}
