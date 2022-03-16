#include "../includes/mini_RT.h"

void	my_mlx_pixel_put(t_tracer *rt, int x, int y, int color)
{
	char	*dst;

	dst = rt->img.addr + (y * rt->img.line_length + x * (rt->img
			.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	colorize(t_coord color)
{
	int	rgb;

	rgb = 255 * color.x;
	rgb <<= 8;
	rgb += 255 * color.y;
	rgb <<= 8;
	rgb += 255 * color.z;
	return (rgb);
}

int	vector_in_color(t_coord vector)
{
	int rgb;

	rgb = (int)(255 * vector.x);
	rgb <<= 8;
	rgb += (int)(255 * vector.y);
	rgb <<= 8;
	rgb += (int)(255 * vector.z);
	return (rgb);
}