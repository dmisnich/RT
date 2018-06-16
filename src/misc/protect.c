/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:15:29 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/23 11:15:31 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		protect_obj(t_sdl *sdl)
{
	int		i;

	i = 0;
	while (i < sdl->scene->max_obj)
	{
		if (sdl->scene->obj[i].tan > 1.0)
			sdl->scene->obj[i].tan = 1.0;
		if (sdl->scene->obj[i].tan < -1.0)
			sdl->scene->obj[i].tan = -1.0;
		if (sdl->scene->obj[i].specular < 1)
			sdl->scene->obj[i].specular = 1;
		i++;
	}
}

void		protect_light(t_sdl *sdl)
{
	int		i;

	i = 0;
	while (i < sdl->max.max_spot)
	{
		if (sdl->light[i].intensity < 0.0)
			sdl->light[i].intensity = 0.0;
		if (sdl->light[i].intensity > 1.0)
			sdl->light[i].intensity = 1.0;
		i++;
	}
}
