/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:59:00 by tekim             #+#    #+#             */
/*   Updated: 2021/06/24 18:06:35 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int			put_minus(t_info *info, char **tmp)
{
	int		i;

	i = 0;
	if ((info->type == 'i' || info->type == 'd') &&
					info->zero == 0 && info->is_negative == 1)
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
	if (info->is_negative == 1 && info->zero == 1)
	{
		if (len >= info->width)
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

	len = ft_numlen(num, info); //숫자의 길이(양수값만)
	ret = (info->prec > len) ? info->prec : len; //.precision이 숫자의 길이보다 길면 ret = prec 아니면  ret = len
	if (!(*tmp = (char *)malloc(sizeof(char) * ret + 1))) //전체 길이만큼 할당
		return (0);
	i = 0;
	(*tmp)[ret] = '\0';
	while (len + i < ret) // .precision이 있는 경우 '0'으로 채워줌
	{
		(*tmp)[i] = '0';// tmp의 주소값을 넘겨주므로 printf_num함수에서 선언된 *tmp의 인덱스로 생각하면 편함
		i++;
	}
	i = 1; //인덱스 초기화
	if (num == 0 && info->prec != 0)//num = 0 인경우
		(*tmp)[ret - i] = '0';
	while (num) //뒤에서 부터 넣어줌 itoa처럼
	{
		(*tmp)[ret - i] = ft_baseset(info->type)[num % info->nbr_base];
		num /= info->nbr_base;
		i++;
	}
	return (len);
}

int			p_type(char **tmp)
{
	*tmp = ft_strjoin("0x", *tmp); //주솟값을 넘겨서 붙힘
	return (ft_strlen(*tmp));
}

int			print_num(signed long long num, t_info *info)
{
	char	*tmp;
	int		len;
	int		ret;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16; //value_info에서 nbr_base=10으로 설정 해 놓음
	if ((info->type == 'd' || info->type == 'i') && num < 0) //음수일 경우 플래그체크 해주고 양수로 변환
	{
		info->is_negative = 1;
		num = num * -1;
	}
	len = put_prec(num, info, &tmp); // .precision이 있는 경우 .precision과 num의 값을 뒤에서 부터 넣어줌
	len += put_minus(info, &tmp); // zero 플래그가 0 이고, 음수일 경우 .precision넣고 strjoin을 통해 앞에 '-'넣어줌
	if (info->type == 'p')
		len = p_type(&tmp);
	ret = put_width(&tmp, info); //width를 채워줌 print_s.c 파일에 있는 함수 return = width의 값 or 숫자의 길이
	ret += put_minus_with_zero(info, &tmp, len); //-를 채워줌 zero 플래그가 1인 경우
	ft_putstr(tmp);
	free(tmp);
	return (ret);
}
