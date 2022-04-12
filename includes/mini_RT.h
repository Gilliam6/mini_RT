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
# define RANGE_ERR			"Argument is out of range\n"
# define READ_ERR			"Cannot read this file\n"

//WINDOW SETTINGS
# define WIN_SIZE_WIDTH		1024.0
# define WIN_SIZE_HEIGHT	800.0

//BUTTONS
# define ESC_BUTTON			53

//RENDER
# define EPSILON			0.001


typedef struct s_cylinder_solution
{
	double x;
	double y;
	double z;
	double w;
} t_vec4;

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
	t_color			color;
	t_coord			xyz;
	double			diameter;
	struct s_sphere	*next;
}				t_sphere;

typedef struct s_plane
{
	t_color			color;
	t_coord			xyz;
	t_coord			vector;
	struct s_plane	*next;
}				t_plane;

typedef struct s_cylinder
{
	t_color				color;
	t_coord				xyz;
	t_coord				vector;
	double				height;
	double				diameter;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct s_objects
{
	t_plane		*plane;
	double 		plane_sol;
	t_sphere	*sphere;
	t_vec2 		sphere_sol;
	t_cylinder	*cyl;
} t_objects;

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
	double			solve;
	t_coord			light_dir;
	t_coord			reflect_vec;
	t_coord			normal;
	t_coord			point;
	t_coord			final_coord;
//	t_objects		*touched_object; //объект пересечение с которым ближе всего
	t_coord 		amb_color;
	t_coord			final_color;
}				t_tracer;

typedef struct s_calculation
{
	t_coord ca;
	t_coord oc;
	double caca;
	double card;
	double caoc;
	double a;
	double b;
	double c;
	double h;
	double t;
	double y;
	t_coord xyz;
} t_sphere_calc;

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
int		parse_coordinates(char **split, t_tracer *rt, void *ptr);
int		parse_vector(char **split, t_tracer *rt, void *ptr);
int		parse_fov(char **split, t_tracer *rt);
void	find_struct(t_coord coord, t_tracer *rt);

//UTILITIES
double	ft_atod(char *str); //string to double convert

//CHECK_STR
double	check_double(char *str);
int		check_ints(char *str);
double	check_double_in_arr(char *str); // only commas, points and digits
int		check_ony_one_int(char *str);
int		check_argv(char *path);

//ADD LISTS
void	add_sphere_back(t_sphere **lst, t_sphere *new);
void	add_plane_back(t_plane **lst, t_plane *new);
void	add_cylinder_back(t_cylinder **lst, t_cylinder *new);

//FREE
void	free_main_struct(t_tracer *rt);

//RENDER
void	render(t_tracer *rt);
void	my_mlx_pixel_put(t_tracer *rt, int x, int y, int color);
int		colorize(t_color color, double bright);
int	vector_in_color(t_coord vector);

t_coord	vector_sub(t_coord vec1, t_coord vec2);
t_coord	vector_sub_val(t_coord vec1, double vec2);

t_coord	vector_pow(t_coord vec1, t_coord vec2);
t_coord	vector_add(t_coord vec1, t_coord vec2);
t_coord	vector_add_val(t_coord vec1, double vec2);
t_coord vector_del_value(t_coord v, double x);

t_coord	vector_del(t_coord vec1, t_coord vec2);
t_coord vector_pow_value(t_coord v1, double value);
double	scalar_product(t_coord v1, t_coord v2);
double	magnitude(t_coord v1);
t_coord	normalize(t_coord v1);

double	scalar_product(t_coord v1, t_coord v2);
t_coord init_vector(double x, double y, double z);
t_coord init_vector_from_rgb(t_color color);

t_vec2	ray_intersect( t_coord cam, t_coord dir, t_coord sphere, double
radius);
int 	first_intersect_sphere(t_tracer *rt, t_coord dir);
double	plaIntersect(t_coord cam, t_coord dir, t_plane *plane);
int 	first_intersect_plane(t_tracer *rt, t_coord dir);
int first_intersect_cyl(t_tracer *rt, t_coord dir);

int	check_intersects(t_tracer *rt, t_coord dir);

//MAIN
int	unexpected_exit(const char *str, t_tracer *rt);

#endif
