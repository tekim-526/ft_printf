/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:29:59 by tekim             #+#    #+#             */
/*   Updated: 2021/06/17 21:22:33 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int					ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int					print_c(int c, t_info *info)
{
	int				ret;

	ret = 0;
	if ((*info).type == '%' && (*info).minus == 1)
		(*info).zero = 0;
	if ((*info).minus == 1)
		ret += ft_putchar(c);
	ret += printf_width((*info).width, 1, (*info).zero);
	if ((*info).minus == 0)
		ret += ft_putchar(c);
	return(ret);
}

int					printf_width(int width, int len, int zero)
{
	int				ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		ret++;
	}
	return (ret);
}