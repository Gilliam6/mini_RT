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
# define FILE_ERR			"Error\n"

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

typedef struct s_a_light
{

};

typedef struct s_light
{

};

typedef struct s_camera
{

};

typedef struct s_sphere
{

};

typedef struct s_plane
{

};

typedef struct s_cylinder
{

};

typedef struct s_tracer
{
	void			*mlx;
	void			*win;
	t_img_data		*img;
}				t_tracer;

//HOOKS
int	keyboard_hook(int key, t_tracer *rt);
int destroy_window(t_tracer *rt);

//PARSER
int	parse_rt_file(t_tracer *rt, char *path);

#endif
