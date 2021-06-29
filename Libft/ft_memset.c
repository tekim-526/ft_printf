/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:25:18 by tekim             #+#    #+#             */
/*   Updated: 2021/05/04 15:43:02 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *ptr, int value, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		*((char *)ptr + i) = value;
		i++;
	}
	return (ptr);
}
