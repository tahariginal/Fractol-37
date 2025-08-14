/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:33:45 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/27 10:40:25 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

void	initialize_c(t_point *c, t_point z, t_fractol *fractal)
{
	if (fractal->name[0] == 'j')
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else if (fractal->name[0] == 'm' || fractal->name[0] == 'b')
	{
		c->x = z.x;
		c->y = z.y;
	}
}

t_point	choose_eq(t_point z, t_point c, t_fractol *fractal)
{
	if (fractal->name[0] == 'm' || fractal->name[0] == 'j')
		return (sum_point(square_point(z), c));
	else if (fractal->name[0] == 'b')
		return (sum_point(cube_point(z), c));
	return (z);
}

void	painter(int x, int y, t_fractol *fractal)
{
	int		i;
	t_point	z;
	t_point	c;

	i = 1;
	z.x = (scale(x, -2, 2, W) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 2, -2, H) * fractal->zoom) + fractal->shift_y;
	initialize_c(&c, z, fractal);
	while (i < fractal->iteration)
	{
		z = choose_eq(z, c, fractal);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			fractal->color = scale(i, BLACK, WHITE, fractal->iteration);
			my_mlx_pixel_put(&fractal->img, x, y, fractal->color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, 0x011711);
}

void	render_fractal(t_fractol *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
			painter(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
