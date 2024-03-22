/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:13:33 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/18 01:34:38 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cc main.c -lmlx -framework OpenGL -framework AppKit ; ./a.out

#include "fractol.h"

int arg_is_valid(int ac, char **av)
{
    return ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || 
    (ac == 4 && !ft_strncmp(av[1], "julia", 5)) || 
    (ac == 2 && !ft_strncmp(av[1], "burning", 7)));
}

int main(int ac, char **av)
{
    t_fractol   fractal;

    if (arg_is_valid(ac, av))
    {
        fractal.name = av[1];
        if ((ac == 4 && !ft_strncmp(av[1], "julia", 5)))
        {
            fractal.julia_x = atodbl(av[2]);
            fractal.julia_y = atodbl(av[3]);
        }
        init_fractal(&fractal);
        render_fractal(&fractal);
        mlx_loop(fractal.mlx);
    }
    else
    {
        puts("Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n\t\"./fractol burning\"");
        exit(0);
    }
}
