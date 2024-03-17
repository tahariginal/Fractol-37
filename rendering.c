/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:33:45 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/17 21:59:23 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void    init_c(t_point *c, t_point *z, t_fractol *fractal)
{
    if (fractal->name[0] == 'j')
    {
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
    else if (fractal->name[0] == 'm')
    {
        c->x = z->x;
        c->y = z->y;
    }
}

void    treat_pixcel(int x, int y, t_fractol *fractal)
{
    int         i;
    int         color;
    t_point z;
    t_point c;

    i = 0;
    z.x = (scale(x, -2, 2, W) * fractal->zoom) + fractal->shift_x;
    z.y = (scale(y, 2, -2, H) * fractal->zoom) + fractal->shift_y;
    init_c(&c, &z, fractal);
    while (i < fractal->iteration)
    {
        //z = z^2 + c
        z = sum_point(square_point(z), c);
        if ((z.x * z.x) + (z.y * z.y) > 4)
        {
            color = scale(i, BLACK, WHITE ,  fractal->iteration);
            my_mlx_pixel_put(&fractal->img, x, y, color * 2);
            return ;
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->img, x, y, 0xffffe0);
}

void    render_fractal(t_fractol *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < H)
    {

        x = -1;
        while (++x < W)
            treat_pixcel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);

}
