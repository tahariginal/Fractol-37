/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:45:21 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/20 00:55:24 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mini/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define H 500
# define W 500
//colors
# define BLACK 0x000000
# define WHITE 0xffffff

typedef unsigned char	t_byte;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
}						t_data;

typedef struct s_fractol
{
	void				*mlx;
	void				*win;
	char				*name;
	int					iteration;
	double				zoom;
	double				shift_x;
	double				shift_y;
	double				julia_x;
	double				julia_y;
	int					color;
	t_data				img;
}						t_fractol;
typedef struct s_point
{
	double x; // real
	double y; // i
}						t_point;
//strings_fcts
double					atodbl(char *s);
int						ft_strncmp(char *s1, char *s2, size_t n);
//init_fractal_strct
void					init_fractal(t_fractol *fractal);
//rendering
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					render_fractal(t_fractol *fractal);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
//math_fcts
double					scale(double unscaled_num, double new_min,
							double new_max, double old_max);
t_point					sum_point(t_point z, t_point c);
t_point					square_point(t_point z);
t_point					cube_point(t_point z);
void					f_abs(t_point *z);
//events_hooks
int						close_win(t_fractol *fractol);
int						key_handel(int keysem, t_fractol *fractol);
int						mousse_handel(int button, int x, int y,
							t_fractol *fractol);

#endif
