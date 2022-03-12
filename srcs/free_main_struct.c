#include "../includes/mini_RT.h"

void	free_main_struct(t_tracer *rt)
{
	if (rt->ambient)
		free(rt->ambient);
	if (rt->camera)
		free(rt->camera);
	if (rt->cyl)
		free(rt->cyl);
	if (rt->plane)
		free(rt->plane);
	if (rt->sphere)
		free(rt->sphere);
	if (rt->light)
		free(rt->light);
}