/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:33:16 by tekim             #+#    #+#             */
/*   Updated: 2021/05/10 17:24:20 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, char *src, size_t size)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (dest[i] && i < size)
		i++;
	while (src[n] && (i + n + 1) < size)
	{
		dest[i + n] = src[n];
		n++;
	}
	if (i < size)
		dest[i + n] = '\0';
	return (i + ft_strlen(src));
}
