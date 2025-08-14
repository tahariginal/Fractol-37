/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fct00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:36:57 by tkoulal           #+#    #+#             */
/*   Updated: 2024/03/27 10:54:31 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

#include <unistd.h>

int	count_dot(char *s)
{
	int	i;
	int	c;

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

void	is_s_valid01(char *s)
{
	int	i;
	int	check_point;

	i = 0;
	check_point = count_dot(s);
	if (check_point > 1)
	{
		msg("syntax Error!");
		exit(1);
	}
	while (s[i])
	{
		if (s[i] == '.' && !ft_isdigit(s[i + 1]))
		{
			msg("SYNTAX ERROR !");
			exit(1);
		}
		i++;
	}
}

void	is_s_valid(char *s)
{
	int	i;

	i = 0;
	is_s_valid01(s);
	is_s_valid02(s);
	while (s[i])
	{
		if (s[i + 1] == '.' && !s[i + 2])
		{
			msg("SYNTAX ERROR !");
			exit(1);
		}
		i++;
	}
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || *s == '.' || *s == '-' || *s == '+'))
		{
			msg("SYNTAX ERROR !");
			exit(1);
		}
		s++;
	}
}
