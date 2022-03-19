#ifndef MINI_RT_H
# define MINI_RT_H
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

//PARCER ITEMS
# define LIGHT				"L"
# define AMBIENT			"A"
# define CAMERA				"C"
# define SPHERE				"sp"
# define PLANE				"pl"
# define CYLINDER			"cy"

//ERR CODES
# define ARG_ERR			"Invalid number of arguments\n"
# define FILE_ERR			"Error\n"
# define PARSE_ERR			"File parse Error\n"

//WINDOW SETTINGS
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
	int R;
	int G;
	int B;
}				t_color;

typedef struct s_vector2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct s_coordinate {
	double x;
	double y;
	double z;
}				t_coord;

typedef struct s_light
{
	t_coord		xyz;
	double 		bright;
	t_color		color;
}				t_light;

typedef struct s_camera
{
	t_coord		xyz;
	t_coord 	vector;
	int			FOV;
}				t_camera;

typedef struct s_ambient
{
	t_color		color;
	double		bright;
}				t_ambient;

typedef struct s_sphere
{
	t_color		color;
	t_coord		xyz;
	double		diameter;
}				t_sphere;

typedef struct s_plane
{
	t_color		color;
	t_coord		xyz;
	t_coord		vector;
}				t_plane;

typedef struct s_cylinder
{
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
	t_img_data		img;
	t_ambient		*ambient;
	t_camera		*camera;
	t_cylinder		*cyl;
	t_light			*light;
	t_plane			*plane;
	t_sphere		*sphere;
	unsigned char	parsing_type;
	t_vec2			solve;
	t_coord			light_dir;
	t_coord			normal;
	t_coord			point;
}				t_tracer;

//HOOKS
int		keyboard_hook(int key, t_tracer *rt);
int 	destroy_window(t_tracer *rt);

//PARSER
int		parse_rt_file(t_tracer *rt, char *path);
int		check_indentifier(char *indent, t_tracer *rt);
int		check_xyz(char **xyz);
int		check_diameter(double diameter);
int		stop_parse(char **xyz);

int		fill_object(char **split, t_tracer *rt);
int		fill_environ(char **split, t_tracer *rt);
int		fill_struct(char **split, t_tracer *rt);
int		fill_ambient(char **split, t_tracer *rt);
int		fill_camera(char **split, t_tracer *rt);
int		fill_light(char **split, t_tracer *rt);
int		fill_sphere(char **split, t_tracer *rt);
int		fill_plane(char **split, t_tracer *rt);
int		fill_cylinder(char **split, t_tracer *rt);

double	parse_bright(char **split);
t_color	parse_colors(char **split);
int		parse_coordinates(char **split, t_tracer *rt);
int		parse_vector(char **split, t_tracer *rt);
int		parse_fov(char **split, t_tracer *rt);
void	find_struct(t_coord coord, t_tracer *rt);

//UTILITIES
double	ft_atod(char *str); //string to double convert

//FREE
void	free_main_struct(t_tracer *rt);

//RENDER
void	render(t_tracer *rt);
void	my_mlx_pixel_put(t_tracer *rt, int x, int y, int color);
int		colorize(t_color color, double bright);
int	vector_in_color(t_coord vector);

t_coord	vector_sub(t_coord vec1, t_coord vec2);
t_coord	vector_pow(t_coord vec1, t_coord vec2);
t_coord	vector_add(t_coord vec1, t_coord vec2);
t_coord	vector_del(t_coord vec1, t_coord vec2);
t_coord vector_pow_value(t_coord v1, double value);
double	scalar_product(t_coord v1, t_coord v2);
double	magnitude(t_coord v1);
t_coord	normalize(t_coord v1);

double	scalar_product(t_coord v1, t_coord v2);
t_coord init_vector(double x, double y, double z);

//MAIN
int	unexpected_exit(const char *str, t_tracer *rt);

#endif
