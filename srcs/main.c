#include "../includes/mini_RT.h"

int	unexpected_exit(const char *str)
{
	printf("%s", str);
	exit (1);
}

void	hooks_extension(t_tracer rt)
{
	mlx_hook(rt.win, 2, 1L << 0, keyboard_hook, &rt);
	mlx_hook(rt.win, 17, 0L, destroy_window, &rt);
}

int main(int argc, char **argv)
{
	t_tracer	rt;

	(void)argv;
	if (argc != 2)
		unexpected_exit(ARG_ERR);
	if (!parse_rt_file(&rt, argv[1]))
		unexpected_exit(FILE_ERR);
	rt.mlx = mlx_init();
	rt.win = mlx_new_window(rt.mlx, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, "mini_RT");

	hooks_extension(rt);
	mlx_loop(rt.mlx);
	return (0);
}
