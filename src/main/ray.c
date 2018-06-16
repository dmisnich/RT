/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:53:25 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/03 12:53:28 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					g_iter;

void				raycaster(t_sdl *sdl)
{
	int				x;
	int				y;
	int				color;

	sdl->buff = sdl->surface->pixels;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			sdl->ray.dir = find_ray_diraction(sdl, x - (WIDTH / 2),
				(HEIGHT / 2) - y);
			sdl->ray.dir = vector_norm(&sdl->ray.dir);
			color = ray_tracer_obj(sdl);
			sdl->buff[x + y * WIDTH] = color;
			x++;
		}
		y++;
	}
}

int					draw_scene(t_sdl *sdl)
{
	t_object		*obj;
	t_object		*ret;
	t_ray			ray;

	g_iter = 0;
	ray.pos = sdl->camera.cam;
	ray.dir = sdl->ray.dir;
	sdl->closest = INFINITY;
	while (g_iter < sdl->scene->max_obj)
	{
		ret = scene_calc_obj_one(sdl, &ray, obj, ret);
		ret = scene_calc_obj_two(sdl, &ray, obj, ret);
		g_iter++;
	}
	if (sdl->closest == INFINITY)
		return (0);
	return (color_test(&sdl->color, find_normal(ret, sdl)));
}

t_object			*scene_calc_obj_two(t_sdl *sdl, t_ray *ray,
	t_object *obj, t_object *ret)
{
	if (sdl->scene->obj[g_iter].name == CYLINDRE &&
		(obj = find_cylindre(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
	if (sdl->scene->obj[g_iter].name == CONE &&
		(obj = find_cone(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
	if (sdl->scene->obj[g_iter].name == CYLINDRE_CUT &&
		(obj = find_cylindre_cut(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
	if (sdl->scene->obj[g_iter].name == CONE_CUT &&
		(obj = find_cone_cut(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
	return (ret);
}

t_object			*scene_calc_obj_one(t_sdl *sdl, t_ray *ray,
	t_object *obj, t_object *ret)
{
	if (sdl->scene->obj[g_iter].name == SPHERE &&
		(obj = find_sphere(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
	if (sdl->scene->obj[g_iter].name == PLANE &&
		(obj = find_plane(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
			if (sdl->scene->obj[g_iter].name == ELLIPSOID &&
		(obj = find_ellips(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
	if (sdl->scene->obj[g_iter].name == PARABOLOID &&
		(obj = find_paraboloid(&sdl->scene->obj[g_iter], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
		{
			sdl->closest = obj->dist;
			sdl->color = obj->color;
			ret = obj;
		}
	}
	return (ret);
}

int					ray_tracer_obj(t_sdl *sdl)
{
	if (sdl->scene->name == SCENE_1)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_2)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_3)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_4)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_5)
		return (draw_scene(sdl));
	return (0);
}
