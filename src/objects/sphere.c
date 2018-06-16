/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:13:44 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/11 11:13:46 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	*find_sphere(t_object *obj, t_ray *ray)
{
	t_vector	oc;
	float		discrim;
	float		param[3];

	oc = vector_sub(&ray->pos, &obj->pos);
	param[0] = vector_dot(&ray->dir, &ray->dir);
	param[1] = 2 * vector_dot(&oc, &ray->dir);
	param[2] = vector_dot(&oc, &oc) - obj->radius * obj->radius;
	return (find_solve_discrim(param, obj));
}
