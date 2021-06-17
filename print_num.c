/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:59:00 by tekim             #+#    #+#             */
/*   Updated: 2021/06/17 21:19:29 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int			put_minus(t_info *info, char **tmp)
{
	int		i;

	i = 0;
	if (((*info).type == 'i' || (*info).type == 'd') &&
					(*info).zero == 0 && (*info).is_negative == 1)
	{
		*tmp = ft_strjoin("-", *tmp);
		i = 1;
	}
	return (i);
}

int			put_minus_with_zero(t_info *info, char **tmp, int len)
{
	int		i;

	i = 0;
	if ((*info).is_negative == 1 && (*info).zero == 1)
	{
		if (len >= (*info).width)
		{
			*tmp = ft_strjoin("-", *tmp);
			i = 1;
		}
		else
			*tmp[0] = '-';
	}
	return (i);
}

int			put_prec(unsigned long long num, t_info *info, char **tmp)
{
	int		len;
	int		ret;
	int		i;

	len = ft_numlen(num, info);
	ret = ((*info).prec > len) ? (*info).prec : len;
	if (!(*tmp = (char *)malloc(sizeof(char) * ret + 1)))
		return (0);
	i = 0;
	(*tmp)[ret] = '\0';
	while (len + 1 < ret)
	{
		*tmp[i] = '0';
		i++;
	}
	i = 1;
	if (num == 0 && (*info).prec != 0)
		(*tmp)[ret - i] = '0';
	while (num)
	{
		(*tmp)[ret - i] = ft_baseset((*info).type)[num % (*info).nbr_base];
		num /= (*info).nbr_base;
		i++;
	}
	return (len);
}

int			p_type(char **tmp)
{
	*tmp = ft_strjoin("0x", *tmp);
	return (ft_strlen(*tmp));
}

int			print_num(unsigned long long num, t_info *info)
{
	char	*tmp;
	int		len;
	int		ret;

	if ((*info).type == 'x' || (*info).type == 'X' || (*info).type == 'p')
		(*info).nbr_base = 16;
	if (((*info).type == 'd' || (*info).type == 'i') && num < 0)
	{
		(*info).is_negative = 1;
		num *= -1;
	}
	len = put_prec(num, info, &tmp);
	len += put_minus(info, &tmp);
	if ((*info).type == 'p')
		len = p_type(&tmp);
	ret = put_width(&tmp, info);
	ret += put_minus_with_zero(info, &tmp, len);
	ft_putstr(tmp);
	free(tmp);
	return (ret);
}
