/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:52:36 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/03 12:52:38 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_scene_1(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.5;
	sdl->camera.cam.y = 10.0;
	sdl->camera.cam.z = -50.0;
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_1;
	sdl->scene->max_obj = 4;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 6);
	help1_init_scene_1(&sdl->scene->obj);
	help2_init_scene_1(&sdl->scene->obj);
}

void	init_scene_2(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 10.0;
	sdl->camera.cam.z = -40.0;
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_2;
	sdl->scene->max_obj = 1;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 2);
	sdl->scene->obj[0].name = CONE_CUT;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = 0.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].n.x = 0.0;
	sdl->scene->obj[0].n.y = 1.0;
	sdl->scene->obj[0].n.z = 0.0;
	sdl->scene->obj[0].tan = 1.0;
	sdl->scene->obj[0].c_max = 5.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 255;
	sdl->scene->obj[0].color.b = 0;
	sdl->scene->obj[0].specular = 100;
}

void	init_scene_3(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 10.0;
	sdl->camera.cam.z = -80.0;
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_3;
	sdl->scene->max_obj = 2;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 2);
	help1_init_scene_3(&sdl->scene->obj);
}

void	init_scene_4(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.2;
	sdl->camera.cam.y = 5.0;
	sdl->camera.cam.z = -40.0;
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_4;
	sdl->scene->max_obj = 4;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 4);
	help1_init_scene_4(&sdl->scene->obj);
	help2_init_scene_4(&sdl->scene->obj);
}

void	init_scene_5(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 1.0;
	sdl->camera.cam.z = -20.0;
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_5;
	sdl->scene->max_obj = 5;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 5);
	sdl->scene->obj[0].name = SPHERE;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = -1.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 90;
	sdl->scene->obj[0].color.b = 90;
	sdl->scene->obj[0].specular = 100;
	help1_init_scene_5(&sdl->scene->obj);
	help2_init_scene_5(&sdl->scene->obj);
}
