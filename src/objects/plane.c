/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:40:10 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/11 14:40:11 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	*find_plane(t_object *obj, t_ray *ray)
{
	t_vector	oc;
	float		res;
	float		dist;

	obj->n = vector_norm(&obj->n);
	oc = vector_sub(&ray->pos, &obj->pos);
	dist = -vector_dot(&oc, &obj->n) / vector_dot(&ray->dir, &obj->n);
	if (dist > 0.00001)
	{
		obj->dist = dist;
		return (obj);
	}
	return (NULL);
}
