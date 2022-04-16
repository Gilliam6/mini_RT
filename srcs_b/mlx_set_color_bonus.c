/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:16:59 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/16 13:28:06 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/mini_RT_bonus.h"

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
