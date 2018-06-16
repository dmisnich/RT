/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_6_cylindre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:28:57 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/24 12:28:59 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	scene_6_cylindre_further(t_object **obj)
{
	(*obj)[4].name = CYLINDRE;
	(*obj)[4].radius = 1.0;
	(*obj)[4].pos.x = -5.0;
	(*obj)[4].pos.y = 0.0;
	(*obj)[4].pos.z = 10.0;
	(*obj)[4].n.x = 0.0;
	(*obj)[4].n.y = 1.0;
	(*obj)[4].n.z = 0.0;
	(*obj)[4].color.r = 0;
	(*obj)[4].color.g = 230;
	(*obj)[4].color.b = 255;
	(*obj)[4].specular = 100;
	(*obj)[5].name = CYLINDRE;
	(*obj)[5].radius = 1.0;
	(*obj)[5].pos.x = 5.0;
	(*obj)[5].pos.y = 0.0;
	(*obj)[5].pos.z = 10.0;
	(*obj)[5].n.x = 0.0;
	(*obj)[5].n.y = 1.0;
	(*obj)[5].n.z = 0.0;
	(*obj)[5].color.r = 0;
	(*obj)[5].color.g = 230;
	(*obj)[5].color.b = 255;
	(*obj)[5].specular = 100;
}

void	scene_6_plane_near(t_object **obj)
{
	(*obj)[6].name = CYLINDRE;
	(*obj)[6].radius = 1.0;
	(*obj)[6].pos.x = -5.0;
	(*obj)[6].pos.y = 0.0;
	(*obj)[6].pos.z = -15.0;
	(*obj)[6].n.x = 0.0;
	(*obj)[6].n.y = 1.0;
	(*obj)[6].n.z = 0.0;
	(*obj)[6].color.r = 0;
	(*obj)[6].color.g = 230;
	(*obj)[6].color.b = 255;
	(*obj)[6].specular = 100;
	(*obj)[7].name = CYLINDRE;
	(*obj)[7].radius = 1.0;
	(*obj)[7].pos.x = 5.0;
	(*obj)[7].pos.y = 0.0;
	(*obj)[7].pos.z = -15.0;
	(*obj)[7].n.x = 0.0;
	(*obj)[7].n.y = 1.0;
	(*obj)[7].n.z = 0.0;
	(*obj)[7].color.r = 0;
	(*obj)[7].color.g = 230;
	(*obj)[7].color.b = 255;
	(*obj)[7].specular = 100;
}
