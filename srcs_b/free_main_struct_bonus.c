/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main_struct_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:38:07 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/16 13:28:01 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/mini_RT_bonus.h"

static inline void	free_multi_obj2(t_tracer *rt, int flag)
{	
	if (flag == 6)
		free(rt->cyl);
	else if (flag == 5)
		free(rt->plane);
	else if (flag == 4)
		free(rt->sphere);
}

void	free_multi_obj(t_tracer *rt, void *ptr, int flag)
{
	void	*copy;

	if (flag == 6)
		copy = (t_cylinder *)ptr;
	else if (flag == 5)
		copy = (t_plane *)ptr;
	else if (flag == 4)
		copy = (t_sphere *)ptr;
	while (ptr)
	{
		copy = ptr;
		if (flag == 6)
			ptr = ((t_cylinder *)ptr)->next;
		else if (flag == 5)
			ptr = ((t_plane *)ptr)->next;
		else if (flag == 4)
			ptr = ((t_sphere *)ptr)->next;
		free(ptr);
	}
	free_multi_obj2(rt, flag);
}

void	free_main_struct(t_tracer *rt)
{
	if (rt->ambient)
		free(rt->ambient);
	if (rt->camera)
		free(rt->camera);
	if (rt->cyl)
		free_multi_obj(rt, rt->cyl, 6);
	if (rt->plane)
		free_multi_obj(rt, rt->plane, 5);
	if (rt->sphere)
		free_multi_obj(rt, rt->sphere, 4);
	if (rt->light)
		free(rt->light);
}
