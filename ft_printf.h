/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimts <kimts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:25:27 by tekim             #+#    #+#             */
/*   Updated: 2021/06/17 18:47:32 by kimts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>

# define TYPE "csdiupxX%"

typedef struct	s_info
{
	int			minus; //왼쪽 정렬
	int			zero;  //출력하는 width의 남는 공간에 0으로 정렬 = -1
	int			width; // = -1 flag
	int			prec;  // = -1 flag
	int			nbr_base; // = 10
	int			is_negative;
	char		type;
	char		pad; //= ' ' zero 플래그에 따라 바꿔줌
}				t_info;

//print char
int			ft_putchar(char c);
int			print_c(int c, t_info *info);
int			printf_width(int width, int len, int zero);

//print string
int			put_width(char **tmp, t_info *info);
char		*parsing_tmp(char *str, int end, int len);
int			ft_putstr(char *s);
int			print_s(char *str, t_info *info);

//print num
char		*ft_baseset(char type);
int			print_num(unsigned long long num, t_info *info);
int			p_type(char **tmp);
int			put_prec(unsigned long long num, t_info *info, char **tmp);
int			put_minus_with_zero(t_info *info, char **tmp, int len);
int			put_minus(t_info *info, char **tmp);

//ft_printf
int			ft_printf(const char *format, ...);
int			parsing_format(va_list ap, char *format);
void		width_prec_check(va_list ap, char *format, t_info *info, int i);
void		flag_check(va_list ap, t_info *info, char *format, int i);
int			print_type(va_list ap, t_info *info);

//side
void		info_value(t_info *info);//ft_printf
int			ft_numlen(unsigned long long nbr, t_info *info);//print_num
char		*ft_baseset(char type);//print_num

//side2
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *str, int c);
void		*ft_memmove(void *dest, const void *src, size_t num);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);


#endif