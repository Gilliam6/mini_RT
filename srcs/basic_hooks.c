#include "../includes/mini_RT.h"
#include <sys/time.h>

int destroy_window(t_tracer *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	exit(0);
}

void new_light_xyz(t_tracer *rt)
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	rt->light->xyz.y = tv.tv_usec / 10000 % 20;
	rt->light->xyz.x = tv.tv_usec / 10000 % 20;
}

int	keyboard_hook(int key, t_tracer *rt)
{
	printf("%d\n", key);
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
	render(rt);
	return (0);
}