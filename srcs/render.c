#include "../includes/mini_RT.h"
void	print_vector(t_coord v)
{
	printf("%f x\n%f y\n%f z\n", v.x, v.y, v.z);
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

int	check_shadow(t_tracer *rt) // check это сфера от которой
// проверяем тень
{
	t_sphere *start; // tmp переменная для пробега по сферам
	t_vec2 points;
	t_coord shadow;

	if (scalar_product(rt->light_dir, rt->normal) < 0)
		shadow = vector_sub_val(rt->point, 0.001);
	else
		shadow = vector_add_val(rt->point, 0.001);
	start = rt->sphere;
	while (start)
	{
		points = ray_intersect(shadow, rt->light_dir, start->xyz,
							   start->diameter / 2.0);
		if (points.x > 0)
			return(1);
		start = start->next;
	}
	return (0);
}

int	cast_ray(t_tracer *rt, t_coord dir)
{
	t_coord	shadow;
	double diffuse;
	if (!check_intersects(rt, dir))
		return (0); //
	rt->point = vector_add(vector_pow_value(dir, rt->solve),
						   rt->camera->xyz);// координаты точек пересечения
	rt->light_dir = normalize(vector_sub(rt->light->xyz, rt->point));
	rt->normal = normalize(vector_sub(rt->point, rt->final_coord));
	diffuse = scalar_product(rt->light_dir, rt->normal); // угол
	// между нормалью и источником света
	diffuse = fmax(compute_reflect(rt, dir) + diffuse, 0);
	diffuse = fmin(rt->light->bright * diffuse, 1.0); // множитель яркости света
	if (check_shadow(rt))
		return(vector_in_color(vector_pow(rt->final_color, rt->amb_color)));
	diffuse = pow(diffuse, 0.45); // гамма коррекция

	shadow = vector_pow(rt->final_color, init_vector(diffuse,
													diffuse,
													diffuse)
	);//
	return (fmax(vector_in_color(shadow), vector_in_color(vector_pow
	(rt->final_color, rt->amb_color))));
}

void	render(t_tracer *rt)
{
	int	x;
	int	y;
	t_coord ray_direct;
	t_coord dir;

	double ratio = WIN_SIZE_WIDTH / WIN_SIZE_HEIGHT;
	double radiana = (rt->camera->FOV / 2 * M_PI) / 180;
	double FOV = WIN_SIZE_WIDTH / tan(radiana);
//	double FOV_2 = tan(radiana/2) * WIN_SIZE_WIDTH;
	rt->amb_color = vector_pow_value(init_vector_from_rgb(rt->ambient->color)
			, rt->ambient->bright);
	ray_direct.z = rt->camera->vector.z;
	y = 0;
	while (y < WIN_SIZE_HEIGHT)
	{
		x = 0;
		ray_direct.y = (WIN_SIZE_HEIGHT / 2 - (double)y - rt->move_y) /
				WIN_SIZE_HEIGHT;
		while (x < WIN_SIZE_WIDTH)
		{
			ray_direct.x = ((double)(x + rt->move_x) - WIN_SIZE_WIDTH/2) /
					FOV / ratio;
			dir = normalize(ray_direct);
			my_mlx_pixel_put(rt, x, y, cast_ray(rt, dir));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.img, 0, 0);
}


