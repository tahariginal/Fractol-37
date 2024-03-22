/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:36:57 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/20 02:24:59 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
//0.3.
int	count_dot(char *s)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '.')
			c++;
	i++;
	}
	return (c);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

void	is_s_valid(char *s)
{
	int i;
	int check_point;

	i = 0;
	check_point = count_dot(s);
	if (check_point > 1)
	{
		puts("syntax Error!");
		exit(1);
	}
	while (s[i])
	{
		if (s[i] == '.' && !ft_isdigit(s[i + 1]))
		{
			puts("SYNTAX ERROR !");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i + 1] == '.' && !s[i + 2])
		{
			puts("SYNTAX ERROR !");
			exit(1);
		}
	i++;
	}
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || *s == '.' || *s == '-' || *s == '+'))
		{
			puts("SYNTAX ERROR !");
			exit(1);
		}
		s++;
	}
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;
	is_s_valid(s);
	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

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
