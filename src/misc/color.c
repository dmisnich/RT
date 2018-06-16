/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:56:47 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/23 14:56:49 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned int		color_test(t_color *color_obj, float value)
{
	t_color			color;
	unsigned int	c;

	color.r = color_obj->r * value;
	color.g = color_obj->g * value;
	color.b = color_obj->b * value;
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	c = (color.r << 16) + (color.g << 8) + color.b;
	return (c);
}
