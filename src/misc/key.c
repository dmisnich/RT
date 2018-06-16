/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:29:36 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/15 13:29:38 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			key_1(t_sdl *sdl, const Uint8 *keykey)
{
	int			hook;

	hook = 0;
	if (sdl->event.type == SDL_QUIT || (sdl->event.type == SDL_KEYDOWN
	&& sdl->event.key.keysym.sym == SDLK_ESCAPE))
		sdl->done = 1;
	else if (keykey[SDL_SCANCODE_UP])
	{
		hook = UP;
		cam_move(sdl, hook);
	}
	else if (keykey[SDL_SCANCODE_DOWN])
	{
		hook = DOWN;
		cam_move(sdl, hook);
	}
	else if (keykey[SDL_SCANCODE_RIGHT])
	{
		hook = RIGHT;
		cam_move(sdl, hook);
	}
	else
		return ;
	raycaster(sdl);
	SDL_UpdateWindowSurface(sdl->win);
}

void			key_2(t_sdl *sdl, const Uint8 *keykey)
{
	int			hook;

	hook = 0;
	if (keykey[SDL_SCANCODE_LEFT])
	{
		hook = LEFT;
		cam_move(sdl, hook);
	}
	else if (keykey[SDL_SCANCODE_R])
	{
		hook = PLUS;
		cam_move(sdl, hook);
	}
	else if (keykey[SDL_SCANCODE_E])
	{
		hook = MINUS;
		cam_move(sdl, hook);
	}
	else
		return ;
	raycaster(sdl);
	SDL_UpdateWindowSurface(sdl->win);
}

void			cam_move(t_sdl *sdl, int hook)
{
	if (hook == UP)
		sdl->camera.cam.y = sdl->camera.cam.y + 0.5;
	if (hook == DOWN)
		sdl->camera.cam.y = sdl->camera.cam.y - 0.5;
	if (hook == LEFT)
		sdl->camera.cam.x = sdl->camera.cam.x - 0.5;
	if (hook == RIGHT)
		sdl->camera.cam.x = sdl->camera.cam.x + 0.5;
	if (hook == PLUS)
		sdl->camera.cam.z = sdl->camera.cam.z + 0.5;
	if (hook == MINUS)
		sdl->camera.cam.z = sdl->camera.cam.z - 0.5;
}
