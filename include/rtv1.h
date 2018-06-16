/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:49:20 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/28 11:49:23 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIDTH		900
# define HEIGHT		900
# define AMBIENT	1
# define POINT		2
# define DIR		3

# define SPHERE			1
# define PLANE			2
# define CYLINDRE		3
# define CONE			4
# define CYLINDRE_CUT	5
# define CONE_CUT		6

# define ELLIPSOID		7
# define PARABOLOID		8
# define TORUS			9

# define SCENE_1	1
# define SCENE_2	2
# define SCENE_3	3
# define SCENE_4	4
# define SCENE_5	5

# define UP			1
# define DOWN		2
# define LEFT		3
# define RIGHT		4
# define PLUS		5
# define MINUS		6

# define SCENE		1

# define DIST		sdl->dist

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <../libft/libft.h>
# include "../Frameworks/SDL2.framework/Headers/SDL.h"

typedef struct		s_max
{
	int				max_spot;
}					t_max;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_discrim
{
	float			x1;
	float			x2;
}					t_discrim;

typedef	struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

typedef struct		s_shadow
{
	t_vector		pos;
	t_vector		dir;
}					t_shadow;

typedef struct		s_light
{
	int				type;
	float			intensity;
	t_vector		pos;
	t_vector		dir;
	t_shadow		shadow;
}					t_light;

typedef struct		s_viewport
{
	float			h;
	float			w;
	float			dist;
}					t_viewport;

typedef	struct		s_cam
{
	t_vector		cam;
}					t_cam;

typedef	struct		s_ray
{
	t_vector		pos;
	t_vector		dir;
}					t_ray;

typedef	struct		s_object
{
	float			radius;
	float			tan;
	float			dist;
	float			dist_max;
	float			c_max;
	int				name;
	t_color			color;
	t_vector		pos;
	t_vector		n;
	float			specular;
	float			*param_e;
}					t_object;

typedef struct		s_scene
{
	t_object		*obj;
	int				name;
	int				max_obj;
}					t_scene;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*surface;
	SDL_Event		event;
	unsigned int	*buff;
	t_viewport		vp;
	t_ray			ray;
	t_cam			camera;
	t_scene			*scene;
	t_light			*light;
	float			closest;
	float			dist;
	int				done;
	t_color			color;
	t_discrim		ts;
	t_max			max;
}					t_sdl;


t_object 			*find_ellips(t_object *obj, t_ray *ray);
t_object 			*find_paraboloid(t_object *obj, t_ray *ray);
t_object			*find_cone_cut(t_object *obj, t_ray *ray);
t_object			*find_cylindre_cut(t_object *obj, t_ray *ray);
float				ellips_normal(t_object *ret, t_sdl *sdl);
float				paraboloid_normal(t_object *ret, t_sdl *sdl);
void				init_scene_7(t_sdl *sdl);

//    NEW FILES UP

void				init_camera(t_sdl *sdl);
void				init_sdl(t_sdl *sdl);
void				init_sphare(t_sdl *sdl);
void				init_plane(t_sdl *sdl);
void				init_cylindre(t_sdl *sdl);
void				init_figure(t_sdl *sdl);
void				raycaster(t_sdl *sdl);
t_vector			find_ray_diraction(t_sdl *sdl, int x, int y);

int					parse_obj(t_sdl *sdl);
void				msg(void);

int					ray_tracer_obj(t_sdl *sdl);

t_object			*find_sphere(t_object *obj, t_ray *ray);
t_object			*find_cylindre(t_object *obj, t_ray *ray);
t_object			*find_cone(t_object *obj, t_ray *ray);
t_object			*find_plane(t_object *obj, t_ray *ray);

t_vector			vector_sub(t_vector *v1, t_vector *v2);
t_vector			vector_add(t_vector *v1, t_vector *v2);
t_vector			vector_mult(t_vector *v1, t_vector *v2);
t_vector			vector_mult_scal(t_vector *v, float value);
t_vector			vector_div(t_vector *v, float value);
t_vector			vector_norm(t_vector *v);

float				vector_dot(t_vector *v1, t_vector *v2);
float				vector_len(t_vector *v);

unsigned int		color(t_sdl *sdl, int i, float value);
unsigned int		color_p(t_sdl *sdl);
float				findelight(t_vector *p, t_vector *norm,
					t_sdl *sdl, t_object *ret);
void				init_light(t_sdl *sdl);

t_object			*find_solve_discrim(float *param, t_object *obj);

void				init_scene_1(t_sdl *sdl);
void				init_scene_2(t_sdl *sdl);
void				init_scene_3(t_sdl *sdl);
void				init_scene_4(t_sdl *sdl);
void				init_scene_5(t_sdl *sdl);
void				init_scene_6(t_sdl *sdl);

int					parser_av(t_sdl *sdl, char *av);

void				help1_init_scene_1(t_object **obj);
void				help2_init_scene_1(t_object **obj);
void				help1_init_scene_3(t_object **obj);
void				help1_init_scene_4(t_object **obj);
void				help2_init_scene_4(t_object **obj);
void				help1_init_scene_5(t_object **obj);
void				help2_init_scene_5(t_object **obj);

void				scene_6_sphere1_up1(t_object **obj);
void				scene_6_sphere1_down1(t_object **obj);
void				scene_6_sphere1_up2(t_object **obj);
void				scene_6_sphere1_down2(t_object **obj);
void				scene_6_plane_1(t_object **obj);
void				scene_6_plane_2(t_object **obj);
void				scene_6_cylindre_further(t_object **obj);
void				scene_6_plane_near(t_object **obj);

int					draw_scene(t_sdl *sdl);
float				light(t_sdl *sdl, int i, t_object *ret, t_discrim tsp);
float				find_normal(t_object *ret, t_sdl *sdl);
float				sphere_normal(t_object *ret, t_sdl *sdl);
float				cylindre_normal(t_object *ret, t_sdl *sdl);
float				plane_normal(t_object *ret, t_sdl *sdl);
float				cone_normal(t_object *ret, t_sdl *sdl);

void				cam_move(t_sdl *sdl, int hook);
void				key_1(t_sdl *sdl, const Uint8	*keykey);
void				key_2(t_sdl *sdl, const Uint8	*keykey);

unsigned int		color_test(t_color *color_obj, float value);

int					shadow(t_sdl *sdl, t_light *light, t_vector *p);
int					shadow_light(t_sdl *sdl, t_light *light, t_vector *p);

void				protect_obj(t_sdl *sdl);
void				protect_light(t_sdl *sdl);
void				shadow_calc_help(t_sdl *sdl, t_ray *ray,
					t_object *obj, int i);
void				finde_light_helper(t_vector *norm, t_object *ret,
					t_sdl *sdl, t_vector *p);

t_object			*scene_calc_obj_one(t_sdl *sdl, t_ray *ray,
					t_object *obj, t_object *ret);
t_object			*scene_calc_obj_two(t_sdl *sdl, t_ray *ray,
					t_object *obj, t_object *ret);

#endif
