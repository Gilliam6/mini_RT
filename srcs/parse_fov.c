/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:40:04 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 22:40:06 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	parse_fov(char **split, t_tracer *rt)
{
	int	fov;

	fov = ft_atod(split[0]);
	if (fov < 0 || fov > 180)
		return (0);
	rt->camera->fov = fov;
	return (1);
}
