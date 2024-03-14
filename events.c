/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 04:08:40 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/14 04:59:47 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int close_win(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img.img);
    mlx_destroy_window(fractol->mlx,  fractol->win);
    mlx_destroy_display(fractol->mlx);
    free(fractol->mlx);
    exit(1);
}
int key_handel(int keysem, t_fractol *fractol)
{
    if (keysem == XK_Escape)
        close_win(fractol);
    else if (keysem ==XK_Up)
        fractol->shift_y += .25;
    else if (keysem ==XK_Down)
        fractol->shift_y -= .25;
    else if (keysem ==XK_Left)
        fractol->shift_x -= .25;
    else if (keysem ==XK_Right)
        fractol->shift_x += .25;
    else if (keysem ==XK_u)
        fractol->iteration += 1;
    else if (XK_d)
        fractol->iteration -= 1;
    render_fractal(fractol);
    return (1);
}
