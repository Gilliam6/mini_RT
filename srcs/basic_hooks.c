#include "../includes/mini_RT.h"
#include <sys/time.h>

int destroy_window(t_tracer *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(0);
}

int	keyboard_hook(int key, t_tracer *rt)
{
	if (key == ESC_BUTTON)
		destroy_window(rt);
	if (key == 32)
	{
		struct timeval tv;
		gettimeofday(&tv, 0);
		rt->light->xyz.y = tv.tv_usec / 10000 % 20;
		rt->light->xyz.x = tv.tv_usec / 10000 % 20;

//		printf("%d\n", key);
		render(rt);
	}
	return (0);
}