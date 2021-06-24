/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:39:01 by tekim             #+#    #+#             */
/*   Updated: 2021/06/24 16:58:58 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int				print_type(va_list ap, t_info *info)
{
	int			ret;
	char		type;

	ret = 0;
	type = info->type;
	if (type == 'c') // 'c'의 경우 .precision을 무시함
		ret = print_c(va_arg(ap, int), info);
	else if (type == '%')
		ret = print_c('%', info);
	else if (type == 's')
		ret = print_s(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		ret = print_num(va_arg(ap, int), info); // 부호 있는 10진 정수
	else if (type == 'x' || type == 'X' || type == 'u')
		ret = print_num(va_arg(ap, unsigned int), info);//부호 없는 16진 정수(unsigned int 범위)"x,X"로 해석, 부호 없는 10진 정수(signed int 범위)'u'로 해석
	else if (type == 'p')
		ret = print_num(va_arg(ap, unsigned long long), info);//포인터가 참조하고 있는 메모리의 주소 값 (8자리의 16진수)
	return (ret);
}

void			flag_check(va_list ap, t_info *info, char *format, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1; //width, .preciosion(d,i,u,x,X)에서 나온 빈자리를 0으로 채움, '-'와 사용 될 경우 무시됨 
	else if (format[i] == '-')
		info->minus = 1; //좌측 정렬을 수행함
	else if (format[i] == '.')
		info->prec = 0; //c, p의 경우 무시하고 출력 (d,i,u,x,X) 플래그에 0이 주어지면 0무시하고 처리, s와 쓰일 때 아무것도 출력 안함 .n이 나오면 경우가 다름
	else if (ft_isdigit(format[i]) || format[i] == '*')
		width_prec_check(ap, format, info, i);
}

void			width_prec_check(va_list ap, char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1) //width인 경우 parsing_format 에서 반복문을 돌면서 값을 넣어줌
			info->width =info->width * 10 + format[i] - '0';
		else //.precision에 값을 계속 넣어줌
			info->prec = info->prec * 10 + format[i] - '0';
	}
	else if (format[i] == '*') // ex) %*.*d
	{
		if (info->prec == -1) // ex) %*.10d
		{
			info->width = va_arg(ap, int);
			if (info->width < 0) //애스터 리스크에 들어오는게 음수일 경우 -플래그에 값을 줌
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else // ex) %10.*d
			info->prec = va_arg(ap, int);
	}
}

int				parsing_format(va_list ap, char *format)
{
	int			i; //인덱스
	int			ret; //리턴
	t_info		*info; //구조체를 사용하기 위해 선언

	i = 0;//초기화
	ret = 0;//초기화
	if (!(info = malloc(sizeof(t_info))))
		return (-1); //구조체 할당, 할당 실패시 리턴은 -1 일반적으로 printf의 리턴은 양수값을 가지기 때문에 -1을 줌
	while (format[i])
	{
		while (format[i] != '%' && format[i]) //%만나기 전까지의 값을 출력
			ret += ft_putchar(format[i++]); //putchar는 임의로 int형으로 만듬 리턴을 받기 위해
		if (format[i] == '%') //출력하다가 %(Format Tag)를 만났을 때
		{
			info_value(info); //구조체에 임의로 설정한 디폴트값(?)을 넣어줌 ==>>> printf_side.c에 있음
			while (format[++i] && !(ft_strchr(TYPE, format[i]))) //%뒤에 바로 type이 나올 수 도 있지만 width, .precision, flag가 나올 수 있기 때문에 체크를 해주는 부분
				flag_check(ap, info, format, i);
			info->type = format[i++]; // 플래그 체크 끝났으므로 i++해줘서 서식지정자(type)을 확인함
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0; // '-'일 경우 좌측정렬이므로, 프리시전이 있을 경우 '0'플래그를 무시하고 처리함
			ret += print_type(ap, info); //type에 맞게 출력
		}
	}
	free(info);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	int			ret;//printf 의 return = 글자수
	va_list		ap;//가변인자 선언

	va_start(ap, format);//가변인자 시작
	ret = parsing_format(ap, (char *)format);//printf("123%c123%d213", c, d);에서 ""사이를 파싱함
	va_end(ap);
	return (ret);
}
