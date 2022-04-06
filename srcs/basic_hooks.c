/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:39:46 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/06 18:39:58 by pveeta           ###   ########.fr       */
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
	if (key == ESC_BUTTON)
		destroy_window(rt);
	return (0);
}
