#include "../includes/mini_RT.h"

void	print_vector(t_coord v)
{
	printf("%f x\n%f y\n%f z\n", v.x, v.y, v.z);
}

t_vec2	ray_intersect( t_coord cam, t_coord dir, t_coord sphere, double radius )
{
	t_vec2 res;
	t_coord oc = vector_sub(cam, sphere);
	double b = scalar_product(oc, dir);
	double c = scalar_product(oc, oc) - (radius * radius);
	double h = b*b - c;

	if(h < 0.0)
	{
		res.x = -1;
		res.y = -1;
		return (res);
	} // no intersection
	h = sqrt(h);
	res.x = -b - h;
	res.y = -b + h;
	return (res);
}

int	cast_ray(t_tracer *rt, t_coord dir)
{
	t_vec2	it;
	t_coord	shadow;
	t_coord point;
	double diffuse;

	it = ray_intersect(rt->camera->xyz, dir, rt->sphere->xyz,
					   rt->sphere->diameter / 2.0); // точки пересечения сферы
	if (it.x < 0)
		return (colorize(rt->ambient->color, rt->ambient->bright)); //
		// эмбиент лайт
	point = vector_sub(vector_pow_value(dir, it.x), rt->sphere->xyz); //
	// координаты точек пересечения
	diffuse = scalar_product(normalize(vector_sub(rt->light->xyz, point)),
							 normalize(point)); // угол между нормалью и
							 // источником света
	diffuse *= -rt->light->bright; // множитель яркости света

	if (diffuse < 0)
		diffuse = 0;

	t_coord color = init_vector(1.0, 1.0, 1.0);
	shadow = vector_pow(color,init_vector(diffuse, diffuse, diffuse)); //
	// предание цвета
	return(vector_in_color(shadow));
}

void	render(t_tracer *rt)
{
	int	x;
	int	y;
	t_coord ray_direct;
	t_coord dir;

	ray_direct.z = rt->camera->vector.z;

	y = 0;
	while (y < WIN_SIZE_HEIGHT)
	{
		x = 0;
		ray_direct.y = ((double)y - WIN_SIZE_HEIGHT/  2) / WIN_SIZE_HEIGHT;
		while (x < WIN_SIZE_WIDTH)
		{
			ray_direct.x = (((double)x - WIN_SIZE_WIDTH/2) / WIN_SIZE_WIDTH) *
					WIN_SIZE_WIDTH / WIN_SIZE_HEIGHT;
			dir = normalize(ray_direct);
//			cast_ray(rt, dir, x, y);
//			if (ray_intersect(rt, dir, x ,y))
			my_mlx_pixel_put(rt, x, y, cast_ray(rt, dir));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.img, 0, 0);
}

