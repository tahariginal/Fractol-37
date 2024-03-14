/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:36:57 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/13 21:34:35 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((t_byte)s1[i] - (t_byte)s2[i]);
}
void    tuto_msg(char *s)
{
    while (*s)
        write(2, s++, 1);
}