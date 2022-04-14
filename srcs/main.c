/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:27:33 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/13 18:25:59 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

void	unexpected_exit(const char *str, t_tracer *rt)
{
	if (rt)
		free_main_struct(rt);
	if (str)
		printf("%s", str);
	exit (1);
}

void	hooks_extension(t_tracer rt)
{
	mlx_hook(rt.win, 2, 1L << 0, keyboard_hook, &rt);
	mlx_hook(rt.win, 17, 0L, destroy_window, &rt);
}

t_tracer	init_rt(void)
{
	t_tracer	rt;

	rt.move_x = 0;
	rt.move_y = 0;
	rt.solve = 0;
	rt.mlx = 0;
	rt.win = 0;
	rt.light = 0;
	rt.sphere = 0;
	rt.plane = 0;
	rt.cyl = 0;
	rt.camera = 0;
	rt.parsing_type = 0;
	rt.ambient = 0;
	return (rt);
}

int	main(int argc, char **argv)
{
	t_tracer	rt;

	if (check_argv(argv[1], argc))
		exit (1);
	rt = init_rt();
	if (!parse_rt_file(&rt, argv[1]))
		unexpected_exit(FILE_ERR, &rt);
	if (!rt.ambient || !rt.camera || !rt.light)
		unexpected_exit("Error: check letters A, C and L in your map!\n", &rt);
	rt.mlx = mlx_init();
	if (rt.mlx == NULL)
		unexpected_exit("Cannot init mlx", &rt);
	rt.win = mlx_new_window(rt.mlx, WIN_WIDTH, WIN_HEIGHT, "mini_RT");
	if (rt.win == NULL)
		unexpected_exit("Cannot create mlx window", &rt);
	rt.img.img = mlx_new_image(rt.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (rt.img.img == NULL)
		unexpected_exit("Cannot create mlx image", &rt);
	rt.img.addr = mlx_get_data_addr(rt.img.img, &rt.img.bits_per_pixel, \
	&rt.img.line_length, &rt.img.endian);
	render(&rt);
	hooks_extension(rt);
	mlx_loop(rt.mlx);
	free_main_struct(&rt);
	return (0);
}
