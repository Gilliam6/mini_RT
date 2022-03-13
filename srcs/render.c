#include "../includes/mini_RT.h"

void	print_vector(t_coord v)
{
	printf("%f x\n%f y\n%f z\n", v.x, v.y, v.z);
}
int	ray_intersect( t_coord cam, t_coord dir, t_coord sphere, double radius )
{
	t_coord oc = vector_sub(cam, sphere);
	double b = scalar_product(oc, dir);
	double c = scalar_product(oc, oc) - radius * radius;
	double h = b*b - c;
	if( h<0.0 )
		return (0); // no intersection
//	h = sqrt( h );
	return (1);
}
void	render(t_tracer *rt)
{
	int	x;
	int	y;
	t_coord ray_direct;
	t_coord dir;


	ray_direct.z = 1.0;
	y = 0;
	while (y < WIN_SIZE_HEIGHT)
	{
		x = 0;
		ray_direct.y = (y / (WIN_SIZE_HEIGHT - 1));
		while (x < WIN_SIZE_WIDTH)
		{
			ray_direct.x = (x / (WIN_SIZE_WIDTH - 1)) * WIN_SIZE_WIDTH /
					WIN_SIZE_HEIGHT;
			dir = normalize(ray_direct);
			if (ray_intersect(rt->camera->xyz, dir, rt->sphere->xyz,
							  rt->sphere->diameter / 2.0))
				my_mlx_pixel_put(rt, x, y, colorize(rt->sphere->color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.img, 0, 0);
}

