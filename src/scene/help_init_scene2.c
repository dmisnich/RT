/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_init_scene2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:51:58 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/24 12:52:00 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	help1_init_scene_5(t_object **obj)
{
	(*obj)[1].name = SPHERE;
	(*obj)[1].radius = 1.0;
	(*obj)[1].pos.x = 0.0;
	(*obj)[1].pos.y = 2.0;
	(*obj)[1].pos.z = 0.0;
	(*obj)[1].color.r = 200;
	(*obj)[1].color.g = 55;
	(*obj)[1].color.b = 255;
	(*obj)[1].specular = 100;
	(*obj)[2].name = SPHERE;
	(*obj)[2].radius = 1.0;
	(*obj)[2].pos.x = 0.0;
	(*obj)[2].pos.y = 1.0;
	(*obj)[2].pos.z = 0.0;
	(*obj)[2].color.r = 0;
	(*obj)[2].color.g = 34;
	(*obj)[2].color.b = 255;
	(*obj)[2].specular = 100;
}

void	help2_init_scene_5(t_object **obj)
{
	(*obj)[3].name = SPHERE;
	(*obj)[3].radius = 1.0;
	(*obj)[3].pos.x = 1.0;
	(*obj)[3].pos.y = 0.0;
	(*obj)[3].pos.z = 0.0;
	(*obj)[3].color.r = 145;
	(*obj)[3].color.g = 255;
	(*obj)[3].color.b = 0;
	(*obj)[3].specular = 100;
	(*obj)[4].name = PLANE;
	(*obj)[4].pos.x = 0.0;
	(*obj)[4].pos.y = 0.0;
	(*obj)[4].pos.z = 10.0;
	(*obj)[4].color.r = 100;
	(*obj)[4].color.g = 0;
	(*obj)[4].color.b = 200;
	(*obj)[4].n.x = 0.0;
	(*obj)[4].n.y = 0.0;
	(*obj)[4].n.z = 1.0;
}
