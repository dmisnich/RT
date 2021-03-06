/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:35:04 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 18:35:07 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		define_vector(double x, double y, double z)
{
	t_vector	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

static double	specular(t_all *ev, int j, int c, double i)
{
	double		r_dot_v;

	ev->r = reflect_ray(ev->l, ev->n);
	r_dot_v = multy_vec(ev->r, ev->v);
	if (r_dot_v > 0 && ev->light[j].type != AMBIANT)
		i += (ev->light[j].intensity *
			(pow((r_dot_v / (find_len(ev->r) *
				find_len(ev->v))), ev->figure[c].specular)));
	return (MIN_(i, 1));
}

static double	which_light(double *t_max, double i, int j, t_all *ev)
{
	(ev->light[j].type == AMBIANT) ? i += ev->light[j].intensity : 0;
	if (ev->light[j].type == POINT)
	{
		ev->l = vector_minus_vector(ev->light[j].position, ev->p);
		*t_max = 1.0;
	}
	if (ev->light[j].type == DIRECTION)
	{
		ev->light[j].position = normalise(ev->light[j].position);
		ev->l = ev->light[j].position;
		*t_max = MAX;
	}
	return (i);
}

double			compute_lighting(t_all *ev, int c)
{
	double	i;
	int		j;
	double	t_max;
	double	n_l;
	double	t[2];

	i = 0.0;
	j = -1;
	while (++j < ev->num_l)
	{
		i = which_light(&t_max, i, j, ev);
		t[0] = 0.001f;
		t[1] = t_max;
		ev->l = normalise(ev->l);
		closet_interesection(ev, t, ev->p, ev->l);
		if (ev->id != -1 || ev->light[j].intensity <= 0.0)
			continue ;
		n_l = multy_vec(ev->n, ev->l);
		if (n_l > 0 && ev->light[j].intensity > 0.0)
			i += (ev->light[j].intensity * n_l
			/ (find_len(ev->n) * find_len(ev->l)));
		(ev->figure[c].specular >= 0) ? i = specular(ev, j, c, i) : 0;
	}
	return (MIN_(i, 1));
}
