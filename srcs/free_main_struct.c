#include "../includes/mini_RT.h"

void	free_main_struct(t_tracer *rt)
{
	if (rt->ambient)
		free(rt->ambient);
	if (rt->camera)
		free(rt->camera);
	if (rt->cyl)
		free(rt->cyl); // now its's list!
	if (rt->plane)
		free(rt->plane); // now its's list!
	if (rt->sphere)
		free(rt->sphere); // now its's list!
	if (rt->light)
		free(rt->light);
}