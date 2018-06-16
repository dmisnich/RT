/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_6_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:28:48 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/24 12:28:50 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	scene_6_plane_1(t_object **obj)
{
	(*obj)[0].name = PLANE;
	(*obj)[0].pos.x = 0.0;
	(*obj)[0].pos.y = 0.0;
	(*obj)[0].pos.z = 0.0;
	(*obj)[0].color.r = 92;
	(*obj)[0].color.g = 92;
	(*obj)[0].color.b = 92;
	(*obj)[0].n.x = 0.0;
	(*obj)[0].n.y = 1.0;
	(*obj)[0].n.z = 0.0;
	(*obj)[1].name = PLANE;
	(*obj)[1].pos.x = 0.0;
	(*obj)[1].pos.y = 8.0;
	(*obj)[1].pos.z = 0.0;
	(*obj)[1].color.r = 92;
	(*obj)[1].color.g = 92;
	(*obj)[1].color.b = 92;
	(*obj)[1].n.x = 0.0;
	(*obj)[1].n.y = -1.0;
	(*obj)[1].n.z = 0.0;
}

void	scene_6_plane_2(t_object **obj)
{
	(*obj)[2].name = PLANE;
	(*obj)[2].pos.x = 0.0;
	(*obj)[2].pos.y = 0.0;
	(*obj)[2].pos.z = 20.0;
	(*obj)[2].color.r = 0;
	(*obj)[2].color.g = 110;
	(*obj)[2].color.b = 200;
	(*obj)[2].n.x = 0.0;
	(*obj)[2].n.y = 0.0;
	(*obj)[2].n.z = 1.0;
	(*obj)[3].name = SPHERE;
	(*obj)[3].radius = 1.0;
	(*obj)[3].pos.x = 0.0;
	(*obj)[3].pos.y = 2.0;
	(*obj)[3].pos.z = -10.0;
	(*obj)[3].color.r = 255;
	(*obj)[3].color.g = 130;
	(*obj)[3].color.b = 0;
	(*obj)[3].specular = 100;
}
