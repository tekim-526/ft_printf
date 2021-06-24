/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:45:06 by tekim             #+#    #+#             */
/*   Updated: 2021/06/24 16:51:31 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char			*parsing_tmp(char *str, int end, int len)
{
	int			i;
	char		*tmp;

	if (!(end < len)) //.precsion이 문자열의 길이보다 크거나 같을 경우 원래 길이의 문자열을 출력해야함
		end = len;
	if (!(tmp = (char *)malloc((end + 1))))
		return (0);
	i = 0;
	while (i < end) //.precision이 문자열 길이보다 작은 경우 end의 길이만큼 앞에서 출력해야함
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int				put_width(char **tmp, t_info *info)
{
	char		*width;
	int			i;

	if (info->width <= (int)ft_strlen(*tmp)) //width가 주어진 값의 길이보다 작거나 같을 때 width은 무시됨
		return ((int)ft_strlen(*tmp));
	width = (char *)malloc(info->width - ft_strlen(*tmp) + 1); // width가 주어진 값보다 큰 경우 너비값에서 주어진 값을 뺀 길이에다가 값을 채워 줘야함
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*tmp)) //출력할 값에 '0' || ' '을 채워줌 0플래그는 %s에서 undefined behavior임 %s에서
	{
		if (info->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*tmp = ft_strjoin(width, *tmp);//우측정렬해야하므로 width 뒤에 합침
	else
		*tmp = ft_strjoin(*tmp, width);//좌측정렬해야하므로 width 앞에 합침
	return (info->width);
}

int				ft_putstr(char *s)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int				print_s(char *str, t_info *info)
{
	int			ret;
	char		*tmp;

	ret = 0;
	if (str == NULL) //printf에서 null이면 이렇게 표시함
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str); // s에서 .precision에서 설정한 길이가 문자열 보다 길면 원래 문자열 출력
	tmp = parsing_tmp(str, info->prec, ft_strlen(str));//tmp에 문자열을 넣어줌
	ret = put_width(&tmp, info); //값이 넣어진 tmp에 width를 추가 플래그를 고려해서 넣어야함
	ft_putstr(tmp); //출력
	free(tmp); // 다쓴 거 메모리 헤제
	return (ret);
}