/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:17:15 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/12 13:17:16 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	*find_cylindre(t_object *obj, t_ray *ray)
{
	t_vector	oc;
	float		param[3];

	obj->n = vector_norm(&obj->n);
	ray->dir = vector_norm(&ray->dir);
	oc = vector_sub(&ray->pos, &obj->pos);
	param[0] = vector_dot(&ray->dir, &ray->dir)
	- pow(vector_dot(&ray->dir, &obj->n), 2);
	param[1] = 2.0 * vector_dot(&ray->dir, &oc)
	- vector_dot(&ray->dir, &obj->n) * (vector_dot(&oc, &obj->n) * 2);
	param[2] = vector_dot(&oc, &oc)
	- pow(vector_dot(&oc, &obj->n), 2) - pow(obj->radius, 2);
	return (find_solve_discrim(param, obj));
}
