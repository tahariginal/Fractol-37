/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:13:33 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/11 19:13:38 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#define H 500
#define W 500

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_var
{
    void    *mlx;
    void    *win;
    t_data  img;
}   t_var;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
//cc main.c -lmlx -framework OpenGL -framework AppKit ; ./a.out
int main()
{
    t_var   data;
    int     x;
    int     y;

    x = 29;
    y = 29;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, W, H, "fractol");
    data.img.img = mlx_new_image(data.mlx,W, H);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length,&data.img.endian);
    while (++y < H - 30)
    {
        x = 30;
        while (++x < W - 30)
            my_mlx_pixel_put(&data.img, x, y, rand() * 0xffffff);
    }
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
    mlx_loop(data.mlx);
}