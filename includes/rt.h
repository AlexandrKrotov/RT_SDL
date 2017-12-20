#ifndef RT_H
# define RT_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <fsdl.h>

# define D_NAME "RT"
# define D_WIDTH 800
# define D_HEIGHT 600
# define SIZE_LINE D_WIDTH * 4
# define TRUE 1
# define FALSE 0
# define SHADOW 0.30
# define BLUR 2

# define UC unsigned char

typedef struct s_vertex t_vertex;
typedef struct s_rt t_rt;
typedef struct s_ray t_ray;
typedef struct s_phong t_phong;
typedef struct s_objs t_objs;
typedef struct s_light t_light;
typedef struct s_m t_m;

struct	s_vertex
{
	double	x;
	double	y;
	double	z;
};

struct	s_ray
{
	t_vertex	o;
	t_vertex	d;
};

struct	s_rt
{
	double		t;
	t_vertex	norm;
	t_vertex	inter;
	SDL_Color		rgb;
	int			n;
	double		amb_int;
	double		dif_int;
	double		spc_int;
};

typedef struct	s_sphere t_sphere;

struct s_sphere
{
	double		radius;
	double		r2;
	int			n;
	t_vertex	center;
	SDL_Color		color;
	double		amb_int;
	double		dif_int;
	double		spc_int;
};

typedef struct	s_sphere_param t_sphere_param;

struct s_sphere_param
{
	t_sphere	*s;
	t_vertex	oc;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;
};

typedef struct	s_plane t_plane;

struct s_plane
{
	t_ray	ray;
	SDL_Color	color;
	int		n;
	double	amb_int;
	double	dif_int;
	double	spc_int;
};

typedef struct	s_cylinder t_cylinder;

struct s_cylinder
{
	t_ray		ray;
	double		r;
	double		r2;
	SDL_Color	color;
	int			n;
	double		amb_int;
	double		dif_int;
	double		spc_int;
};

typedef struct	s_cylinder_param t_cylinder_param;

struct s_cylinder_param
{
	t_cylinder	*cyl;
	t_vertex	oc;
	t_vertex	av;
	t_vertex	cv;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;
};

typedef struct	s_cone t_cone;

struct s_cone
{
	t_ray		ray;
	SDL_Color		color;
	double		alpha;
	double		rad;
	double		cos2;
	double		sin2;
	int			n;
	double		amb_int;
	double		dif_int;
	double		spc_int;
};

typedef struct	s_cone_param t_cone_param;

struct s_cone_param
{
	t_cone		*con;
	t_vertex	oc;
	t_vertex	av;
	t_vertex	cv;
	double		dot_v;
	double		dot_p;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t0;
	double		t1;
};

typedef struct	s_dsp t_dsp;

struct	s_dsp
{
	int	dsp_h;
	int	half_h;
	int	dsp_w;
	int	half_w;
	int	rend_ws;
	int	rend_hs;
	int	rend_we;
	int	rend_he;
};

typedef struct	s_flags t_flags;

struct s_flags
{
	int			redraw;
	int			shadow;
	int			aliasing;
};

typedef struct	s_trans t_trans;

struct s_trans
{
	double		zoom;
	double		shift;
};

typedef struct	s_calc t_calc;

struct s_calc
{
	double		cos_x;
	double		sin_x;
	double		cos_y;
	double		sin_y;
	double		cos_z;
	double		sin_z;
};

struct	s_objs
{
	void			*obj;
	int				(*ft_inter)(t_rt*, t_ray*, struct s_objs*);
	void			(*ft_info)(t_rt*, t_ray*, struct s_objs*);
	struct s_objs	*next;
};

struct	s_phong
{
	SDL_Color		amb;
	SDL_Color		dif;
	SDL_Color		spc;
};

struct	s_light
{
	t_vertex		*o;
	double			power;
	struct s_light	*next;
};

struct s_m
{
	t_lprm  	*lprm;
	t_bool  	loop;
	SDL_Surface	*surf;
	t_dsp		dsp;
	t_objs		*scene;
	t_calc		calc;
	t_light		*light;
	t_vertex	light_default;
	t_phong		phong;
	t_vertex	cam;
	t_rt		rt;
	t_trans		trans;
	t_flags		flags;
	int			x;
	int			y;
};

void			init_m(t_m *all);

int				ft_render(t_m *all);
t_phong			ft_phong(const t_rt *rt, SDL_Color *col, t_vertex l, t_vertex cam);
SDL_Color			ft_light_calc(t_m *all, SDL_Color *color);

int				ft_key_hook(int keycode, t_m *all);

int				ft_mouse_hook(int key, int x, int y, t_m *all);
int				ft_mouse_cord(int x, int y, t_m *all);

t_vertex		ft_sub_vec(t_vertex a, t_vertex b);
t_vertex		ft_sum_vec(t_vertex a, t_vertex b);
double			ft_dot(t_vertex a, t_vertex b);
t_vertex		ft_cross_vector(t_vertex a, t_vertex b);
double			ft_get_magnitude(t_vertex a);
t_vertex		ft_normalized_vector(t_vertex a);
t_vertex		ft_m_v_d(t_vertex a, double b);
t_vertex		ft_divide_vec_double(t_vertex a, double b);
double			ft_cos_vector(t_vertex u, t_vertex v);
t_vertex		ft_reverse_vector(t_vertex a);
t_vertex		ft_reflect_vector(t_vertex a, t_vertex b);

void			ft_add_plane(t_objs *scene, t_vertex o, t_vertex d, SDL_Color c);
void			ft_add_sphere(t_objs *scene, t_vertex o, SDL_Color col, double r);
void			ft_add_cyl(t_objs *scene, t_ray ray, SDL_Color col, double radius);
void			ft_add_cone(t_objs *scene, t_ray ray, SDL_Color col, double a);

int				ft_sphere_intersect(t_rt *rt, t_ray *ray, t_objs *ptr);
int				ft_plane_intersect(t_rt *rt, t_ray *ray, t_objs *ptr);
int				ft_cylinder_intersect(t_rt *rt, t_ray *ray, t_objs *ptr);
int				ft_cone_intersect(t_rt *rt, t_ray *ray, t_objs *ptr);

void			ft_get_info_sphere(t_rt *rt, t_ray *ray, t_objs *ptr);
void			ft_get_info_plane(t_rt *rt, t_ray *ray, t_objs *ptr);
void			ft_get_info_cylinder(t_rt *rt, t_ray *ray, t_objs *ptr);
void			ft_get_info_cone(t_rt *rt, t_ray *ray, t_objs *ptr);

void			ft_get_norm_sphere(t_rt *rt, t_objs *ptr);

void			ft_add_light_lst(t_light *light, t_vertex pos, double pow);

void			ft_scene_init_sphere(t_m *all);
void			ft_scene_init_plane(t_m *all);
void			ft_scene_init_cone(t_m *all);
void			ft_scene_init_cylinder(t_m *all);
void			ft_init_scene_2(t_m *all);
void			ft_init_scene_1(t_m *all);
void			ft_init_multilight(t_m *all);

int				ft_shadow_ray(t_m *all, t_light *light);
void			ft_blur(char *data_in, int n);
void			ft_random_value(t_vertex *v, SDL_Color *c, int *s);
void			ft_add_random_sphere(t_m *all);

t_objs			*ft_find_empty(t_objs *scene, t_objs *ptr);
void			ft_bzero_rgb_arr(SDL_Color *color, int size);
void			ft_ptr_to_rgb(char *ptr, SDL_Color *rgb);

void			ft_error(int error);
int				ft_exit(void);

#endif
