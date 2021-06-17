/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:32:23 by tekim             #+#    #+#             */
/*   Updated: 2021/06/17 18:02:53 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		info_value(t_info *info)
{
	(*info).minus = 0;
	(*info).zero = 0;
	(*info).width = 0;
	(*info).prec = -1;
	(*info).type = 0;
	(*info).nbr_base = 10;
	(*info).is_negative = 0;
}

int			ft_numlen(unsigned long long nbr, t_info *info)
{
	int		i;

	if (nbr == 0 && info->prec != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= info->nbr_base;
		i++;
	}
	return (i);
}

char		*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
