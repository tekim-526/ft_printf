/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:24:32 by tekim             #+#    #+#             */
/*   Updated: 2021/05/06 20:57:13 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		space(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\r' ||
			c == '\f' || c == '\t')
	{
		return (1);
	}
	else
		return (0);
}

int		ft_atoi(const char *str)
{
	int i;
	int a;
	int b;

	i = 0;
	a = 1;
	b = 0;
	while (space(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			a = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		b = b * 10 + str[i] - '0';
		i++;
	}
	return (a * b);
}
