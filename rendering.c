/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:33:45 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/20 05:17:29 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal(t_point *c, t_point z, t_fractol *fractal)
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

void	paint_fractol(int x, int y, t_fractol *fractal)
{
	int		i;
	t_point	z;
	t_point	c;

	i = 0;
	z.x = (scale(x, -2, 2, W) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 2, -2, H) * fractal->zoom) + fractal->shift_y;
	choose_fractal(&c, z, fractal);
	while (i < fractal->iteration)
	{
		//z = z^2 + c
		z = sum_point(square_point(z), c);
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
void	paint_myFractol(int x, int y, t_fractol *fractal)
{
	int		i;
	t_point	z;
	t_point	c;

	i = 0;
	z.x = (scale(x, -2, 2, W) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 2, -2, H) * fractal->zoom) + fractal->shift_y;
	choose_fractal(&c, z, fractal);
	while (i < fractal->iteration)
	{
		//z = z^3 + c
		z = sum_point(cube_point(z), c);
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
		{
			if (fractal->name[0] == 'm' || fractal->name[0] == 'j')
				paint_fractol(x, y, fractal);
			else if (fractal->name[0] == 'b')
				paint_myFractol(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
