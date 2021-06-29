/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:02:19 by tekim             #+#    #+#             */
/*   Updated: 2021/05/07 13:53:48 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t			i;
	const char		*s;
	char			*d;

	if (src == NULL && dest == NULL)
		return (NULL);
	s = src;
	d = dest;
	i = 0;
	if (dest > src)
	{
		while (num)
		{
			if (num < 1)
				break ;
			*(d + num - 1) = *(s + num - 1);
			num--;
		}
	}
	while (i < num)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dest);
}
