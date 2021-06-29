/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:12:59 by tekim             #+#    #+#             */
/*   Updated: 2021/05/05 13:02:57 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	char	*start;

	start = (char *)str;
	while (*str)
		str++;
	while (str != start && *str != (char)c)
		str--;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}
