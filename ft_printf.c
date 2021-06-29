/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:39:01 by tekim             #+#    #+#             */
/*   Updated: 2021/06/22 15:58:01 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_type(va_list ap, t_info *info)
{
	int			ret;
	char		type;

	ret = 0;
	type = info->type;
	if (type == 'c')
		ret = print_c(va_arg(ap, int), info);
	else if (type == '%')
		ret = print_c('%', info);
	else if (type == 's')
		ret = print_s(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		ret = print_num(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		ret = print_num(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		ret = print_num(va_arg(ap, unsigned long long), info);
	return (ret);
}

void			flag_check(va_list ap, t_info *info, char *format, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		width_prec_check(ap, format, info, i);
}

void			width_prec_check(va_list ap, char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - '0';
		else
			info->prec = info->prec * 10 + format[i] - '0';
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

int				parsing_format(va_list ap, char *format)
{
	int			i;
	int			ret;
	t_info		*info;

	i = 0;
	ret = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			info_value(info);
			while (format[++i] && !(ft_strchr(TYPE, format[i])))
				flag_check(ap, info, format, i);
			info->type = format[i++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			ret += print_type(ap, info);
		}
	}
	free(info);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = parsing_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}
