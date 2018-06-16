/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_init_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:42:17 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/03 14:42:28 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	help1_init_scene_1(t_object **obj)
{
	(*obj)[1].name = SPHERE;
	(*obj)[1].radius = 3.0;
	(*obj)[1].pos.x = 0.0;
	(*obj)[1].pos.y = 10.0;
	(*obj)[1].pos.z = 100.0;
	(*obj)[1].color.r = 255;
	(*obj)[1].color.g = 0;
	(*obj)[1].color.b = 0;
	(*obj)[1].specular = 50;
	(*obj)[0].name = CONE;
	(*obj)[0].tan = 0.4;
	(*obj)[0].pos.x = 0.0;
	(*obj)[0].pos.y = 10.0;
	(*obj)[0].pos.z = 100.0;
	(*obj)[0].n.x = 1.0;
	(*obj)[0].n.y = 0.0;
	(*obj)[0].n.z = 0.0;
	(*obj)[0].color.r = 255;
	(*obj)[0].color.g = 128;
	(*obj)[0].color.b = 0;
	(*obj)[0].specular = 20;
}

void	help2_init_scene_1(t_object **obj)
{
	(*obj)[2].name = PLANE;
	(*obj)[2].pos.x = 0.0;
	(*obj)[2].pos.y = -10.0;
	(*obj)[2].pos.z = 150.0;
	(*obj)[2].color.r = 255;
	(*obj)[2].color.g = 222;
	(*obj)[2].color.b = 0;
	(*obj)[2].n.x = 0.0;
	(*obj)[2].n.y = 0.0;
	(*obj)[2].n.z = 1.0;
	(*obj)[3].name = CONE;
	(*obj)[3].tan = 0.4;
	(*obj)[3].pos.x = 0.0;
	(*obj)[3].pos.y = 10.0;
	(*obj)[3].pos.z = 100.0;
	(*obj)[3].n.x = 0.0;
	(*obj)[3].n.y = 1.0;
	(*obj)[3].n.z = 0.0;
	(*obj)[3].color.r = 255;
	(*obj)[3].color.g = 128;
	(*obj)[3].color.b = 0;
	(*obj)[3].specular = 20;
}

void	help1_init_scene_3(t_object **obj)
{
	(*obj)[0].name = CONE;
	(*obj)[0].tan = 0.6;
	(*obj)[0].pos.x = 0.0;
	(*obj)[0].pos.y = 2.0;
	(*obj)[0].pos.z = 0.0;
	(*obj)[0].n.x = 0.0;
	(*obj)[0].n.y = 1.0;
	(*obj)[0].n.z = 0.0;
	(*obj)[0].color.r = 255;
	(*obj)[0].color.g = 0;
	(*obj)[0].color.b = 255;
	(*obj)[0].specular = 200;
	(*obj)[1].name = PLANE;
	(*obj)[1].pos.x = 0.0;
	(*obj)[1].pos.y = 0.0;
	(*obj)[1].pos.z = 0.0;
	(*obj)[1].color.r = 139;
	(*obj)[1].color.g = 139;
	(*obj)[1].color.b = 139;
	(*obj)[1].n.x = 0.0;
	(*obj)[1].n.y = 1.0;
	(*obj)[1].n.z = 0.0;
}

void	help1_init_scene_4(t_object **obj)
{
	(*obj)[0].name = CYLINDRE;
	(*obj)[0].radius = 1.0;
	(*obj)[0].pos.x = 4.0;
	(*obj)[0].pos.y = 0.0;
	(*obj)[0].pos.z = 0.0;
	(*obj)[0].n.x = 0.0;
	(*obj)[0].n.y = 0.0;
	(*obj)[0].n.z = 1.0;
	(*obj)[0].color.r = 255;
	(*obj)[0].color.g = 0;
	(*obj)[0].color.b = 100;
	(*obj)[0].specular = 500;
	(*obj)[1].name = CYLINDRE;
	(*obj)[1].radius = 1.0;
	(*obj)[1].pos.x = 0.0;
	(*obj)[1].pos.y = 0.0;
	(*obj)[1].pos.z = 0.0;
	(*obj)[1].n.x = 0.0;
	(*obj)[1].n.y = 0.0;
	(*obj)[1].n.z = 1.0;
	(*obj)[1].color.r = 255;
	(*obj)[1].color.g = 0;
	(*obj)[1].color.b = 100;
	(*obj)[1].specular = 500;
}

void	help2_init_scene_4(t_object **obj)
{
	(*obj)[2].name = PLANE;
	(*obj)[2].pos.x = 0.0;
	(*obj)[2].pos.y = 0.0;
	(*obj)[2].pos.z = 100.0;
	(*obj)[2].color.r = 255;
	(*obj)[2].color.g = 0;
	(*obj)[2].color.b = 255;
	(*obj)[2].n.x = 0.0;
	(*obj)[2].n.y = 1.0;
	(*obj)[2].n.z = 0.0;
	(*obj)[3].name = CYLINDRE;
	(*obj)[3].radius = 1.0;
	(*obj)[3].pos.x = -4.0;
	(*obj)[3].pos.y = 0.0;
	(*obj)[3].pos.z = 0.0;
	(*obj)[3].n.x = 0.0;
	(*obj)[3].n.y = 0.0;
	(*obj)[3].n.z = 1.0;
	(*obj)[3].color.r = 255;
	(*obj)[3].color.g = 0;
	(*obj)[3].color.b = 100;
	(*obj)[3].specular = 500;
}
