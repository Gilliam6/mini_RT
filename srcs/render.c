#include "../includes/mini_RT.h"

//int	ray_intersect()
void	render(t_tracer *rt)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_SIZE_HEIGHT)
	{
		x = 0;
		while (x < WIN_SIZE_WIDTH)
		{
			my_mlx_pixel_put(rt, x, y, colorize(rt->ambient->color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.img, 0, 0);
	(void)rt;
}

