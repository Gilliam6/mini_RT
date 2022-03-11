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

typedef struct s_color {
	unsigned char R;
	unsigned char G;
	unsigned char B;
}				t_color;

typedef struct s_coordinate {
	double x;
	double y;
	double z;
}				t_coord;

typedef struct s_light
{
	char		*indent;
	t_coord		xyz;
	double 		bright;
	t_color		color;
}				t_light;

typedef struct s_camera
{
	char		*indent;
	t_coord		xyz;
	t_coord 	vector;
	int			FOV;
}				t_camera;

typedef struct s_ambient
{
	char		*indent;
	t_color		color;
	double		bright;
}				t_ambient;

typedef struct s_sphere
{
	char		*indent;
	t_color		color;
	t_coord		xyz;
	double		diameter;
}				t_sphere;

typedef struct s_plane
{
	char		*indent;
	t_color		color;
	t_coord		xyz;
	t_coord		vector;
}				t_plane;

typedef struct s_cylinder
{
	char		*indent;
	t_color		color;
	t_coord		xyz;
	t_coord		vector;
	double		height;
	double		diameter;
}				t_cylinder;



typedef struct s_tracer
{
	void			*mlx;
	void			*win;
	t_img_data		*img;
	t_ambient		*ambient;
	t_camera		*camera;
	t_cylinder		*cyl;
	t_light			*light;
	t_plane			*plane;
	t_sphere		*sphere;
}				t_tracer;

//HOOKS
int	keyboard_hook(int key, t_tracer *rt);
int destroy_window(t_tracer *rt);

//PARSER
int	parse_rt_file(t_tracer *rt, char *path);

#endif
