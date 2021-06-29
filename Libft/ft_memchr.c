/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:00:35 by tekim             #+#    #+#             */
/*   Updated: 2021/05/04 15:42:03 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *str, int c, unsigned int num)
{
	unsigned int	i;
	const void		*tmp;

	i = 0;
	tmp = str;
	while (i < num)
	{
		if (*((char *)tmp + i) == (char)c)
			return ((void *)tmp + i);
		i++;
	}
	return ((void *)0);
}
