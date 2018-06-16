/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_discrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:36:04 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/09 13:36:05 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object		*find_solve_discrim(float *param, t_object *obj)
{
	t_discrim	tsp;
	t_object	*ret;
	float		m[2];
	float		discrim;

	discrim = (param[1] * param[1]) - (4 * param[0] * param[2]);
	if (discrim < 0 && discrim > -0.001)
		discrim = 0;
	if (discrim >= 0)
	{
		if ((tsp.x1 = (-param[1] + sqrtf(discrim)) / (2.0 * param[0])))
		{
			obj->dist = tsp.x1;
			obj->dist_max = tsp.x2;
		}
		if ((tsp.x2 = (-param[1] - sqrtf(discrim)) / (2.0 * param[0]))
			&& tsp.x2 < tsp.x1)
		{
			obj->dist = tsp.x2;
			obj->dist_max = tsp.x1;
		}
		if (tsp.x1 < 0 && tsp.x2 < 0)
			return (NULL);
		if (tsp.x1 < 0 && tsp.x2 > 0)
			obj->dist = tsp.x2;
		else if (tsp.x1 > 0 && tsp.x2 < 0)
			obj->dist = tsp.x1;
		return (obj);
	}
	return (NULL);
}
