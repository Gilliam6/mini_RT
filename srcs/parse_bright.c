/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:43:07 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/07 19:18:12 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

double	parse_bright(char **split)
{
	double	bright;

	bright = ft_atod(split[0]);
	if (bright < 0.0 || bright > 1.0)
		return (-1.0);
	return (bright);
}
