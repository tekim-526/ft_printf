/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:21:43 by tekim             #+#    #+#             */
/*   Updated: 2021/05/26 16:18:13 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*ret;

	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	ret = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
		return (0);
	ft_memmove(ret, s1, len1);
	ft_memmove(ret + len1, s2, len2);
	ret[len1 + len2] = '\0';
	//free((char *)s1);
	return (ret);
}