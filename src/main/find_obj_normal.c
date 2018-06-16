/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:27:27 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/11 12:27:29 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	g_tmp[4];
t_vector	g_p[2];
t_vector	g_norm;
t_vector	g_oc;
t_vector	g_k;
float		g_m;
float		g_res;
float		g_dot;

float		find_normal(t_object *ret, t_sdl *sdl)
{
	if (ret->name == SPHERE)
		return (sphere_normal(ret, sdl));
	if (ret->name == PLANE)
		return (plane_normal(ret, sdl));
	if (ret->name == CYLINDRE)
		return (cylindre_normal(ret, sdl));
	if (ret->name == CONE)
		return (cone_normal(ret, sdl));
	if (ret->name == ELLIPSOID)
		return (ellips_normal(ret, sdl));
	if (ret->name == PARABOLOID)
		return (paraboloid_normal(ret, sdl));
	if (ret->name == CYLINDRE_CUT)
		return (cylindre_normal(ret, sdl));
	if (ret->name == CONE_CUT)
		return (cone_normal(ret, sdl));
	return (0);
}

float		sphere_normal(t_object *ret, t_sdl *sdl)
{
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_norm = vector_sub(&g_p[1], &ret->pos);
	g_norm = vector_mult_scal(&g_norm, 1.0 / vector_len(&g_norm));
	g_norm = vector_norm(&g_norm);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		cylindre_normal(t_object *ret, t_sdl *sdl)
{
	g_oc = vector_sub(&sdl->camera.cam, &ret->pos);
	g_m = (vector_dot(&sdl->ray.dir, &ret->n) * sdl->closest)
	+ vector_dot(&g_oc, &ret->n);
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_tmp[0] = vector_mult_scal(&ret->n, g_m);
	g_tmp[1] = vector_sub(&g_p[1], &ret->pos);
	g_tmp[2] = vector_sub(&g_tmp[0], &g_tmp[1]);
	g_norm = vector_norm(&g_tmp[2]);
	g_norm = vector_mult_scal(&g_norm, -1);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		plane_normal(t_object *ret, t_sdl *sdl)
{
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_norm = vector_norm(&ret->n);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		cone_normal(t_object *ret, t_sdl *sdl)
{
	g_oc = vector_sub(&sdl->camera.cam, &ret->pos);
	g_m = (vector_dot(&sdl->ray.dir, &ret->n) * sdl->closest)
	+ vector_dot(&g_oc, &ret->n);
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_res = 1 + pow(ret->tan, 2);
	g_tmp[0] = vector_mult_scal(&ret->n, g_m);
	g_tmp[1] = vector_mult_scal(&g_tmp[0], g_res);
	g_tmp[2] = vector_sub(&g_p[1], &ret->pos);
	g_norm = vector_sub(&g_tmp[2], &g_tmp[1]);
	g_norm = vector_norm(&g_norm);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		ellips_normal(t_object *ret, t_sdl *sdl)
{
	t_vector	cmid[2];
	t_vector	r;
	float		t1[3];

	t1[0] = ret->tan / 2;
	cmid[0] = vector_mult_scal(&ret->n, t1[0]);
	cmid[1] = vector_add(&ret->pos, &cmid[0]);
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	r = vector_sub(&g_p[1], &cmid[1]);
	t1[0] = 1 - (pow(ret->param_e[1], 2) / pow(ret->param_e[0], 2)); //T1
	t1[1] = vector_dot(&r, &ret->n); //T2
	g_tmp[0] = vector_mult_scal(&ret->n, t1[1]); //T3
	g_tmp[1] = vector_mult_scal(&g_tmp[0], t1[0]); //T4
	g_tmp[2] = vector_sub(&r, &g_tmp[1]);  //T5
	g_norm = vector_norm(&g_tmp[2]);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		paraboloid_normal(t_object *ret, t_sdl *sdl)
{
	float		mk;

	// printf("test\n");
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_m = (vector_dot(&sdl->ray.dir, &ret->n) * sdl->closest)
	+ vector_dot(&g_oc, &ret->n);
	mk = g_m + ret->tan;
	g_tmp[0] = vector_mult_scal(&ret->n, mk);
	g_tmp[1] = vector_sub(&g_p[1], &ret->pos);
	g_tmp[2] = vector_sub(&g_tmp[1], &g_tmp[0]);
	g_norm = vector_norm(&g_tmp[2]);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}