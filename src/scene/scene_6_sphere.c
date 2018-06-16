/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_2_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:11:59 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/24 12:12:00 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	scene_6_sphere1_up1(t_object **obj)
{
	(*obj)[8].name = SPHERE;
	(*obj)[8].radius = 1.5;
	(*obj)[8].pos.x = 5.0;
	(*obj)[8].pos.y = 8.0;
	(*obj)[8].pos.z = 10.0;
	(*obj)[8].color.r = 0;
	(*obj)[8].color.g = 230;
	(*obj)[8].color.b = 255;
	(*obj)[8].specular = 30;
	(*obj)[9].name = SPHERE;
	(*obj)[9].radius = 1.5;
	(*obj)[9].pos.x = -5.0;
	(*obj)[9].pos.y = 8.0;
	(*obj)[9].pos.z = 10.0;
	(*obj)[9].color.r = 0;
	(*obj)[9].color.g = 230;
	(*obj)[9].color.b = 255;
	(*obj)[9].specular = 30;
}

void	scene_6_sphere1_down1(t_object **obj)
{
	(*obj)[10].name = SPHERE;
	(*obj)[10].radius = 1.5;
	(*obj)[10].pos.x = -5.0;
	(*obj)[10].pos.y = 0.0;
	(*obj)[10].pos.z = 10.0;
	(*obj)[10].color.r = 0;
	(*obj)[10].color.g = 230;
	(*obj)[10].color.b = 255;
	(*obj)[10].specular = 30;
	(*obj)[11].name = SPHERE;
	(*obj)[11].radius = 1.5;
	(*obj)[11].pos.x = 5.0;
	(*obj)[11].pos.y = 0.0;
	(*obj)[11].pos.z = 10.0;
	(*obj)[11].color.r = 0;
	(*obj)[11].color.g = 230;
	(*obj)[11].color.b = 255;
	(*obj)[11].specular = 30;
}

void	scene_6_sphere1_up2(t_object **obj)
{
	(*obj)[12].name = SPHERE;
	(*obj)[12].radius = 1.5;
	(*obj)[12].pos.x = 5.0;
	(*obj)[12].pos.y = 8.0;
	(*obj)[12].pos.z = -15.0;
	(*obj)[12].color.r = 0;
	(*obj)[12].color.g = 230;
	(*obj)[12].color.b = 255;
	(*obj)[12].specular = 30;
	(*obj)[13].name = SPHERE;
	(*obj)[13].radius = 1.5;
	(*obj)[13].pos.x = -5.0;
	(*obj)[13].pos.y = 8.0;
	(*obj)[13].pos.z = -15.0;
	(*obj)[13].color.r = 0;
	(*obj)[13].color.g = 230;
	(*obj)[13].color.b = 255;
	(*obj)[13].specular = 30;
}

void	scene_6_sphere1_down2(t_object **obj)
{
	(*obj)[14].name = SPHERE;
	(*obj)[14].radius = 1.5;
	(*obj)[14].pos.x = 5.0;
	(*obj)[14].pos.y = 0.0;
	(*obj)[14].pos.z = -15.0;
	(*obj)[14].color.r = 0;
	(*obj)[14].color.g = 230;
	(*obj)[14].color.b = 255;
	(*obj)[14].specular = 30;
	(*obj)[15].name = SPHERE;
	(*obj)[15].radius = 1.5;
	(*obj)[15].pos.x = -5.0;
	(*obj)[15].pos.y = 0.0;
	(*obj)[15].pos.z = -15.0;
	(*obj)[15].color.r = 0;
	(*obj)[15].color.g = 230;
	(*obj)[15].color.b = 255;
	(*obj)[15].specular = 30;
}
