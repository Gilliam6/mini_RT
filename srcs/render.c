#include "../includes/mini_RT.h"

void	print_vector(t_coord v)
{
	printf("%f x\n%f y\n%f z\n", v.x, v.y, v.z);
}
int	ray_intersect( t_coord cam, t_coord dir, t_coord sphere, double radius )
{
	t_coord oc = vector_sub(cam, sphere);
	double b = scalar_product(oc, dir);
	double c = scalar_product(oc, oc) - (radius * radius);
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


	y = 0;
	while (y < WIN_SIZE_HEIGHT)
	{
		x = 0;
		ray_direct.y = ((double)y - WIN_SIZE_HEIGHT/  2) / WIN_SIZE_HEIGHT;
		while (x < WIN_SIZE_WIDTH)
		{
			ray_direct.x = (((double)x - WIN_SIZE_WIDTH/2) / WIN_SIZE_WIDTH) *
					WIN_SIZE_WIDTH / WIN_SIZE_HEIGHT;
			ray_direct.z = rt->camera->vector.z;
			dir = normalize(ray_direct);
//			printf("%f x %f y %f z\n", dir.x, dir.y, dir.z);
			if (ray_intersect(rt->camera->xyz, dir, rt->sphere->xyz,
							  rt->sphere->diameter / 2.0))
				my_mlx_pixel_put(rt, x, y, colorize(rt->sphere->color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.img, 0, 0);
}

