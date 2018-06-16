/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellips.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:19:55 by dmisnich          #+#    #+#             */
/*   Updated: 2018/06/01 11:19:57 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object *find_ellips(t_object *obj, t_ray *ray)
{
	t_vector	oc;
	float		a1[2];
	float		a2[2];
	float		param[3];
	float		discrim;

	oc = vector_sub(&ray->pos, &obj->pos);
	a1[0] = vector_dot(&ray->dir, &obj->n);
	a1[1] = a1[0] * (2 * obj->tan);
	a2[0] = pow(obj->radius, 2) + vector_dot(&oc, &obj->n);
	a2[1] = 2 * obj->tan * a2[0] - obj->tan;
	param[0] = 4 * pow(obj->radius, 2) * vector_dot(&ray->dir, &ray->dir) - pow(a1[1], 2);
	param[1] = 2 * (4 * pow(obj->radius, 2)) * vector_dot(&ray->dir, &oc) - a1[1] * a2[1] * 2;
	param[2] = 4 * pow(obj->radius, 2) * vector_dot(&oc, &oc) - pow(a2[1], 2);
	obj->param_e = param;
	return (find_solve_discrim(param, obj));
}
