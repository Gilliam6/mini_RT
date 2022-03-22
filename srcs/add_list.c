#include "../includes/mini_RT.h"

void	add_sphere_back(t_sphere **lst, t_sphere *new)
{
	t_sphere	*copy;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		copy = *lst;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
	else
		*lst = new;
	new->next = NULL;
}

void	add_plane_back(t_plane **lst, t_plane *new)
{
	t_plane	*copy;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		copy = *lst;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
	else
		*lst = new;
	new->next = NULL;
}

void	add_cylinder_back(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder	*copy;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		copy = *lst;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
	else
		*lst = new;
	new->next = NULL;
}
