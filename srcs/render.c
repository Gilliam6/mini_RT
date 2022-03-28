#include "../includes/mini_RT.h"
#include <sys/time.h>
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

double	compute_reflect(t_tracer *rt, t_coord dir)
{
	double	reflect;
	rt->reflect_vec = vector_pow_value(rt->normal, scalar_product(dir, rt->normal)
	* 2.0);
	rt->reflect_vec = vector_sub(dir, rt->reflect_vec);
	reflect = scalar_product(rt->light_dir, rt->reflect_vec);
	if (reflect < 0)
		reflect = 0;
	reflect = pow(reflect, 16.0);
	return (reflect);
}

int	check_shadow(t_tracer *rt, t_sphere *check)
{
	t_sphere *start;

	start = rt->sphere;
	while (start)
	{
		if (start == check)
		{
			start = start->next;
			continue;
		}
		else if (ray_intersect(rt->point, rt->light_dir,
									   rt->sphere->xyz,
						  rt->sphere->diameter /2).x>0)
			return(1);
		start = start->next;
	}
	return (0);
}

t_sphere 	*first_intersect(t_tracer *rt, t_coord dir)
{
	t_vec2 tmp;
	t_sphere *final;
	t_sphere *start;

	start = rt->sphere;
	rt->solve.x = 0;
	rt->solve.y = 0;
	while (start)
	{
		tmp = ray_intersect(rt->camera->xyz, dir, start->xyz,
								  start->diameter / 2.0);
		rt->point = vector_add(vector_pow_value(dir, rt->solve.x),
										   rt->camera->xyz);
//		if (check_shadow(rt, start))
//		{
//			start = start->next;
//			continue ;
//		}
		if (!rt->solve.x && tmp.x > 0)
		{
			rt->solve = tmp;
			final = start;
		}
		else if (tmp.x < rt->solve.x && tmp.x > 0)
		{
			rt->solve = tmp;
			final = start;
		}
		start = start->next;
	}
	if (!rt->solve.x)
		rt->solve.x = -1.0;
	return (final);
}

int	cast_ray(t_tracer *rt, t_coord dir)
{
	t_coord	shadow;
	double diffuse;
	t_sphere *final;

	final = first_intersect(rt, dir);
//	rt->solve = ray_intersect(rt->camera->xyz, dir, rt->sphere->xyz,
//					   rt->sphere->diameter / 2.0); // точки пересечения
					   // сферы решаем квадратное уравнение дескриминантой
	if (rt->solve.x < 0)
		return (colorize(rt->ambient->color, rt->ambient->bright)); //
		// эмбиент лайт если луч не попал в сферу
	rt->point = vector_add(vector_pow_value(dir, rt->solve.x),
						   rt->camera->xyz);
	// координаты точек пересечения
	rt->light_dir = normalize(vector_sub(rt->light->xyz, rt->point));
	rt->normal = normalize(vector_sub(rt->point, final->xyz));
	diffuse = scalar_product(rt->light_dir, rt->normal); // угол
	// между нормалью и источником света
	diffuse += compute_reflect(rt, dir);
	diffuse *= rt->light->bright; // множитель яркости света
	if (diffuse > 1.0)
		diffuse = 1.0;
	if (diffuse < 0)
		diffuse = 0;

	t_coord color = init_vector(1.0, 1.0, 1.0); // цвет фигуры по умолчанию
	// белый
	shadow = vector_pow(color,init_vector(diffuse, diffuse, diffuse)); //
	// предание финального цвета
	return(vector_in_color(shadow));
}

void	render(t_tracer *rt)
{
	int	x;
	int	y;
	t_coord ray_direct;
	t_coord dir;
//	rt->amb_color = rt->ambient->color.R / 255 * rt->ambient->bright;
	ray_direct.z = rt->camera->vector.z;

	y = 0;
	while (y < WIN_SIZE_HEIGHT)
	{
		x = 0;
		ray_direct.y = (WIN_SIZE_HEIGHT / 2 - (double)y) / WIN_SIZE_HEIGHT;
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

