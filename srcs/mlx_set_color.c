#include "../includes/mini_RT.h"

void	my_mlx_pixel_put(t_tracer *rt, int x, int y, int color)
{
	char	*dst;

	dst = rt->img.addr + (y * rt->img.line_length + x * (rt->img
			.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	colorize(t_color color)
{
	int	rgb;

	rgb = color.R;
	rgb <<= 8;
	rgb = color.G;
	rgb <<= 8;
	rgb = color.B;
	return (rgb);
}