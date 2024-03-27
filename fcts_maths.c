/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_maths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:54:49 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/27 10:36:39 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

double	scale(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

t_point	sum_point(t_point z, t_point c)
{
	t_point	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_point	cube_point(t_point z)
{
	t_point	result;

	result.x = (z.x * z.x * z.x) - (3 * z.x * (z.y * z.y));
	result.y = (3 * (z.x * z.x) * z.y) - (z.y * z.y * z.y);
	return (result);
}

t_point	square_point(t_point z)
{
	t_point	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
