/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:39:46 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/07 19:17:39 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	destroy_window(t_tracer *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(0);
}

int	keyboard_hook(int key, t_tracer *rt)
{
	struct timeval	tv;

	if (key == ESC_BUTTON)
		destroy_window(rt);
	if (key == 32)
	{
		gettimeofday(&tv, 0);
		rt->light->xyz.y = tv.tv_usec / 10000 % 20;
		rt->light->xyz.x = tv.tv_usec / 10000 % 20;
		render(rt);
	}
	return (0);
}
