/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:39:46 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 17:35:05 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"
#include <sys/time.h>

int	destroy_window(t_tracer *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	free_main_struct(rt);
	exit(0);
}

void new_light_xyz(t_tracer *rt)
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	rt->light->xyz.y = tv.tv_usec / 10000 % 20;
	rt->light->xyz.x = tv.tv_usec / 10000 % 20;
}

void change_something(t_tracer *rt, int key)
{
	if (rt->flag == 1 && key == PLUS_BUTTON)
		rt->sphere->diameter += 1;
	if (rt->flag == 1 && key == MINUS_BUTTON)
		rt->sphere->diameter -= 1;
	if (rt->flag == 2 && key == PLUS_BUTTON)
		rt->cyl->diameter += 1;
	if (rt->flag == 2 && key == MINUS_BUTTON)
		rt->cyl->diameter -= 1;
	if (rt->flag == 3 && key == PLUS_BUTTON)
		rt->cyl->height += 1;
	if (rt->flag == 3 && key == MINUS_BUTTON)
		rt->cyl->height -= 1;
}

void change_flag(t_tracer *rt, int key)
{
	if (key == SPACE)
		rt->flag = 0;
	else
		rt->flag = key - 5;
}
int	keyboard_hook(int key, t_tracer *rt)
{
	if (key == ESC_BUTTON)
		destroy_window(rt);
	if (key == U_BUTTON)
		new_light_xyz(rt);
	if (key == LEFT_BUTTON)
		rt->move_x -= 50;
	if (key == RIGHT_BUTTON)
		rt->move_x += 50;
	if (key == DOWN_BUTTON)
		rt->move_y -= 50;
	if (key == UP_BUTTON)
		rt->move_y += 50;
	if (!rt->flag && key == PLUS_BUTTON && rt->camera->fov < 180)
		rt->camera->fov += 10;
	if (!rt->flag && key == MINUS_BUTTON && rt->camera->fov > 0)
		rt->camera->fov -= 10;
	if (key == C_BUTTON || key == X_BUTTON || key == Z_BUTTON || key == SPACE)
		change_flag(rt, key);
	if (rt->flag)
		change_something(rt, key);
	render(rt);
	return (0);
}