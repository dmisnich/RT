/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:42:23 by dmisnich          #+#    #+#             */
/*   Updated: 2018/06/01 11:42:25 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object		*find_cone_cut(t_object *obj, t_ray *ray)
{
	t_vector	oc;
	float		discrim;
	t_object	*ret;
	float		m[2];
	float		param[3];

	obj->n = vector_norm(&obj->n);
	ray->dir = vector_norm(&ray->dir);
	oc = vector_sub(&ray->pos, &obj->pos);
	param[0] = vector_dot(&ray->dir, &ray->dir)
	- (1 + obj->tan * obj->tan) * (vector_dot(&ray->dir, &obj->n))
	* (vector_dot(&ray->dir, &obj->n));
	param[1] = 2 * vector_dot(&oc, &ray->dir) - (1 + obj->tan * obj->tan)
	* (vector_dot(&ray->dir, &obj->n)) * (vector_dot(&oc, &obj->n) * 2);
	param[2] = vector_dot(&oc, &oc) - (1 + obj->tan * obj->tan) *
	(vector_dot(&oc, &obj->n) * vector_dot(&oc, &obj->n));
	ret = find_solve_discrim(param, obj);
	if (ret != NULL)
	{
		if (ret->dist > 0 && ret->dist < ret->dist_max)
		{
			m[0] = (vector_dot(&ray->dir, &ret->n) * ret->dist) + vector_dot(&oc, &ret->n);
			if (m[0] > 0 && m[0] < obj->c_max)
				return (ret);
		}
		if (ret->dist_max > 0)
		{
			ret->dist = ret->dist_max;
			m[1] = (vector_dot(&ray->dir, &ret->n) * ret->dist_max) + vector_dot(&oc, &ret->n);
			if (m[1] > 0 && m[1] < obj->c_max)
				return (ret);
		}
	}
	return (NULL);
}
