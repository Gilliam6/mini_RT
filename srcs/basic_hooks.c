#include "../includes/mini_RT.h"

int	keyboard_hook(int key, t_tracer *rt)
{
	if (key == ESC_BUTTON)
	{
		mlx_destroy_window(rt->mlx, rt->win);
		exit(0);
	}
	return (0);
}