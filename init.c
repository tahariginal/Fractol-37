/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:28:58 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/14 06:09:28 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_data(t_fractol *fractol)
{
    fractol->iteration = 18;
    fractol->shift_x = 0.0;
    fractol->shift_y = 0.0;
    fractol-> zoom = 1;
}

void    init_event(t_fractol *fractol)
{
    mlx_hook(fractol->win, KeyPress, KeyPressMask, key_handel, fractol);
    mlx_hook(fractol->win, ButtonPress, ButtonPressMask, mousse_handel, fractol);
    mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask, close_win, fractol);
}

void    init_fractal(t_fractol *fractal)
{
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, W, H, fractal->name);
    fractal->img.img = mlx_new_image(fractal->mlx, W, H);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    init_data(fractal);
    init_event(fractal);
}
