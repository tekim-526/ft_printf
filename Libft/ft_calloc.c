/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:09:20 by tekim             #+#    #+#             */
/*   Updated: 2021/05/06 20:27:30 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(unsigned int size, unsigned int count)
{
	void			*ptr;

	if (!(ptr = malloc(size * count)))
		return (NULL);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
