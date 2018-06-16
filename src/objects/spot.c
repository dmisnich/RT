/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:37:09 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/09 13:37:13 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			g_i;
float		g_res;
float		g_res_dot;
float		g_n_dot;
float		g_r_dot_v;
float		g_len_norm;
t_vector	g_r[4];
t_vector	g_l;
t_vector	g_v;

void		shadow_calc_help(t_sdl *sdl, t_ray *ray, t_object *obj, int i)
{
	if (sdl->scene->obj[i].name == SPHERE &&
	(obj = find_sphere(&sdl->scene->obj[i], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
			sdl->closest = obj->dist;
	}
	if (sdl->scene->obj[i].name == CYLINDRE &&
	(obj = find_cylindre(&sdl->scene->obj[i], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
			sdl->closest = obj->dist;
	}
	if (sdl->scene->obj[i].name == CONE &&
	(obj = find_cone(&sdl->scene->obj[i], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
			sdl->closest = obj->dist;
	}
	if (sdl->scene->obj[i].name == PLANE &&
	(obj = find_plane(&sdl->scene->obj[i], ray)) != NULL)
	{
		if (sdl->closest > obj->dist)
			sdl->closest = obj->dist;
	}
}

int			shadow_light(t_sdl *sdl, t_light *light, t_vector *p)
{
	t_object	*obj;
	t_object	*ret;
	t_ray		ray;
	int			i;
	float		dist;

	i = 0;
	ray.dir = vector_sub(&light->pos, p);
	dist = vector_len(&ray.dir);
	ray.dir = vector_norm(&ray.dir);
	ray.pos = vector_mult_scal(&ray.dir, 0.01);
	ray.pos = vector_add(&ray.pos, p);
	sdl->closest = INFINITY;
	while (i < sdl->scene->max_obj)
	{
		shadow_calc_help(sdl, &ray, obj, i);
		i++;
	}
	if (sdl->closest > 0 && sdl->closest < dist)
		return (0);
	return (1);
}

void		finde_light_helper(t_vector *norm, t_object *ret,
t_sdl *sdl, t_vector *p)
{
	if (g_n_dot > 0)
		g_res += (sdl->light[g_i].intensity * g_n_dot) /
	(g_len_norm * vector_len(&g_l));
	if (ret->specular != -1 && (ret->name == SPHERE
	|| ret->name == CYLINDRE || ret->name == CONE))
	{
		g_r[0] = vector_mult_scal(norm, 2);
		g_res_dot = vector_dot(norm, &g_l);
		g_r[1] = vector_mult_scal(&g_r[0], g_res_dot);
		g_r[2] = vector_sub(&g_r[1], &g_l);
		g_r_dot_v = vector_dot(&g_r[2], &g_v);
		if (g_r_dot_v > 0)
			g_res += (sdl->light[g_i].intensity * pow(g_r_dot_v /
			vector_len(&g_r[2]) * vector_len(&g_v), ret->specular));
	}
}

float		findelight(t_vector *p, t_vector *norm, t_sdl *sdl, t_object *ret)
{
	g_i = 0;
	g_res = 0.0;
	g_v = vector_mult_scal(&sdl->ray.dir, -1);
	g_len_norm = vector_len(norm);
	while (g_i < sdl->max.max_spot)
	{
		if (sdl->light[g_i].type == AMBIENT)
			g_res += sdl->light[g_i].intensity;
		else
		{
			if (sdl->light[g_i].type == POINT)
				g_l = vector_sub(&sdl->light[g_i].pos, p);
			else
				g_l = sdl->light[g_i].pos;
			if (!shadow_light(sdl, &sdl->light[g_i], p))
			{
				g_i++;
				continue ;
			}
			g_n_dot = vector_dot(norm, &g_l);
			finde_light_helper(norm, ret, sdl, p);
		}
		g_i++;
	}
	return (g_res);
}
