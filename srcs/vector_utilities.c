#include "../includes/mini_RT.h"

t_coord	vector_sub(t_coord vec1, t_coord vec2)
{
	t_coord	res;

	res.x = vec1.x - vec2.x;
	res.y = vec1.y - vec2.y;
	res.z = vec1.z - vec2.z;
	return (res);
}

t_coord	vector_pow(t_coord vec1, t_coord vec2)
{
	t_coord	res;

	res.x = vec1.x * vec2.x;
	res.y = vec1.y * vec2.y;
	res.z = vec1.z * vec2.z;
	return (res);
}

t_coord	vector_add(t_coord vec1, t_coord vec2)
{
	t_coord	res;

	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;
	return (res);
}

t_coord	vector_del(t_coord vec1, t_coord vec2)
{
	t_coord	res;

	res.x = vec1.x / vec2.x;
	res.y = vec1.y / vec2.y;
	res.z = vec1.z / vec2.z;
	return (res);
}

t_coord vector_pow_value(t_coord v1, double value)
{
	t_coord	v2;

	v2.x = v1.x * value;
	v2.y = v1.y * value;
	v2.z = v1.z * value;
	return (v2);
}

t_coord init_vector(double x, double y, double z)
{
	t_coord res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}