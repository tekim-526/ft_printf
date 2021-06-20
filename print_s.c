/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:45:06 by tekim             #+#    #+#             */
/*   Updated: 2021/06/20 16:10:41 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char			*parsing_tmp(char *str, int end, int len)
{
	int			i;
	char		*tmp;

	if (!(end < len))
		end = len;
	if (!(tmp = (char *)malloc((end + 1))))
		return (0);
	i = 0;
	while (i < end)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int				put_width(char **tmp, t_info *info)
{
	char		*width;
	int			i;

	if ((*info).width <= (int)ft_strlen(*tmp))
		return ((int)ft_strlen(*tmp));
	width = (char *)malloc((*info).width - ft_strlen(*tmp) + 1);
	i = 0;
	while ((size_t)i < (*info).width - ft_strlen(*tmp))
	{
		if ((*info).zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if ((*info).minus == 0)
		*tmp = ft_strjoin(width, *tmp);
	else
		*tmp = ft_strjoin(*tmp, width);
	return ((*info).width);
}

int				ft_putstr(char *s)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int				print_s(char *str, t_info *info)
{
	int			ret;
	char		*tmp;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if ((*info).prec == -1 || (size_t)(*info).prec > ft_strlen(str))
		(*info).prec = ft_strlen(str);
	tmp = parsing_tmp(str, (*info).prec, ft_strlen(str));
	ret = put_width(&tmp, info);
	ft_putstr(tmp);
	free(tmp);
	return (ret);
}