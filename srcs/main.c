#include "../includes/mini_RT.h"

int	unexpected_exit(const char *str, t_tracer *rt)
{
	if (rt)
		free_main_struct(rt);
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

int main(int argc, char **argv)
{
	t_tracer	rt;
	if (argc != 2)
		unexpected_exit(ARG_ERR, 0);
	rt = init_rt();

	if (!parse_rt_file(&rt, argv[1]))
		unexpected_exit(FILE_ERR, &rt);

	rt.mlx = mlx_init();
	rt.win = mlx_new_window(rt.mlx, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, "mini_RT");
	rt.img.img = mlx_new_image(rt.mlx, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
	rt.img.addr = mlx_get_data_addr(rt.img.img, &rt
			.img.bits_per_pixel, &rt.img.line_length, &rt.img.endian);
	render(&rt);
	hooks_extension(rt);
	mlx_loop(rt.mlx);
	free_main_struct(&rt);
	return (0);
}
