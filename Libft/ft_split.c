/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:37:32 by tekim             #+#    #+#             */
/*   Updated: 2021/05/10 23:40:44 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s, char c)
{
	size_t		size;

	size = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
		{
			size++;
			while (*s && *s != c)
				s++;
		}
	}
	return (size);
}

static void		ft_strcpy2(char *dest, char const *src, size_t from, size_t to)
{
	while (from < to)
	{
		*dest = src[from];
		dest++;
		from++;
	}
	*dest = 0;
}

static char		**memory_free(char **memf, size_t size_of_array)
{
	size_t		i;

	i = 0;
	while (i < size_of_array)
	{
		free(memf[i]);
		i++;
	}
	free(memf);
	return (NULL);
}

static char		**operate(char const *s, char c, char **ret)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			k = i;
			while (s[i] != 0 && s[i] != c)
				i++;
			if (!(ret[j] = (char *)malloc(sizeof(char) * (i - k + 1))))
				return (memory_free(ret, j));
			ft_strcpy2(ret[j], s, k, i);
			j++;
		}
		if (!s[i])
			break ;
		i++;
	}
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = ft_len(s, c);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (ret == 0)
		return (NULL);
	ret[len] = 0;
	if (len == 0)
		return (ret);
	return (operate(s, c, ret));
}
