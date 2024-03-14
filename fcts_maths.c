/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_maths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:54:49 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/13 22:28:06 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale(double unscaled_num, double new_min, double new_max, double old_max)
{
    double old_min;
    old_min = 0;
    return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}
