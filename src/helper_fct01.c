/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fct01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:57:32 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/27 11:00:41 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int	count_sign(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '-')
			c++;
		i++;
	}
	return (c);
}

void	is_s_valid02(char *s)
{
	int	check_sign;

	check_sign = count_sign(s);
	if (check_sign > 1)
	{
		msg("syntax Error!");
		exit(1);
	}
}

double	atodbl(char *s)
{
	long	firstpart;
	double	secondepart;
	double	pow;
	int		sign;

	is_s_valid(s);
	firstpart = 0;
	secondepart = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		firstpart = (firstpart * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		secondepart = secondepart + (*s++ - 48) * pow;
	}
	return ((firstpart + secondepart) * sign);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while (n && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	msg(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}
