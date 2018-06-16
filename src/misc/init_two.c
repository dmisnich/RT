/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:56:14 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/24 13:56:15 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_scene_6(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 4.0;
	sdl->camera.cam.z = -45.0;
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_4;
	sdl->scene->max_obj = 16;
	sdl->max.max_spot = 3;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 16);
	scene_6_plane_1(&sdl->scene->obj);
	scene_6_plane_2(&sdl->scene->obj);
	scene_6_cylindre_further(&sdl->scene->obj);
	scene_6_sphere1_up1(&sdl->scene->obj);
	scene_6_sphere1_down1(&sdl->scene->obj);
	scene_6_sphere1_up2(&sdl->scene->obj);
	scene_6_sphere1_down2(&sdl->scene->obj);
	scene_6_plane_near(&sdl->scene->obj);
}

void	init_light(t_sdl *sdl)
{
	sdl->light = (t_light *)malloc(sizeof(t_light) * 5);
	sdl->light[0].type = AMBIENT;
	sdl->light[0].intensity = 0.2;
	sdl->light[1].type = POINT;
	sdl->light[1].intensity = 0.4;
	sdl->light[1].pos.x = -10.0;
	sdl->light[1].pos.y = 4.0;
	sdl->light[1].pos.z = -26.0;
	sdl->light[2].type = POINT;
	sdl->light[2].intensity = 0.4;
	sdl->light[2].pos.x = 10.0;
	sdl->light[2].pos.y = 4.0;
	sdl->light[2].pos.z = -26.0;
	sdl->light[3].type = POINT;
	sdl->light[3].intensity = 0.3;
	sdl->light[3].pos.x = 0.0;
	sdl->light[3].pos.y = 0.0;
	sdl->light[3].pos.z = -20.0;
	sdl->light[4].type = POINT;
	sdl->light[4].intensity = 0.3;
	sdl->light[4].pos.x = 0.0;
	sdl->light[4].pos.y = 0.0;
	sdl->light[4].pos.z = -20.0;
}

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_putstr("error SDL_Init\n");
	sdl->win = SDL_CreateWindow("RTv1", 500, 0,
		WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	sdl->surface = SDL_GetWindowSurface(sdl->win);
	sdl->vp.w = 0.5;
	sdl->vp.h = 0.5;
	sdl->vp.dist = 0.5;
	sdl->done = 0;
}
