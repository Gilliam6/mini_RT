#ifndef MINI_RT_H
# define MINI_RT_H
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# define ARG_ERR			"Invalid number of arguments\n"
# define WIN_SIZE_WIDTH		1024.0
# define WIN_SIZE_HEIGHT	800.0

//BUTTONS
# define ESC_BUTTON			53

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_tracer
{
	void			*mlx;
	void			*win;
	t_img_data		*img;
}				t_tracer;

//HOOKS
int	keyboard_hook(int key, t_tracer *rt);

#endif
