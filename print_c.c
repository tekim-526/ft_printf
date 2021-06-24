/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:29:59 by tekim             #+#    #+#             */
/*   Updated: 2021/06/24 16:30:14 by kimts            ###   ########.fr       */
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
	if (info->type == '%' && info->minus == 1)//'0'이 '-'플래그와 같이 쓰일 경우 무시됨
		info->zero = 0;
	if (info->minus == 1) //'-' 일 경우 '%c' 출력 후 공백 출력
		ret += ft_putchar(c);
	ret += printf_width(info->width, 1, info->zero);
	if (info->minus == 0) //와이드가 있는 경우 '-'가 없으면 width를 먼저 출력 후 문자 출력
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