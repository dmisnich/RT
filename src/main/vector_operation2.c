/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:06:57 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/14 11:06:59 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		vector_div(t_vector *v, float value)
{
	t_vector	res;

	res.x = v->x / value;
	res.y = v->y / value;
	res.z = v->z / value;
	return (res);
}

t_vector		vector_norm(t_vector *v)
{
	return (vector_div(v, vector_len(v)));
}

float			vector_dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

float			vector_len(t_vector *v)
{
	return (sqrt(vector_dot(v, v)));
}
