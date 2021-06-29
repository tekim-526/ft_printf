/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:25:27 by tekim             #+#    #+#             */
/*   Updated: 2021/06/29 16:45:34 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

# define TYPE "csdiupxX%"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	int			nbr_base;
	int			is_negative;
	char		type;
}				t_info;

int				ft_putchar(char c);
int				print_c(int c, t_info *info);
int				printf_width(int width, int len, int zero);

int				put_width(char **tmp, t_info *info);
char			*parsing_tmp(char *str, int end, int len);
int				ft_putstr(char *s);
int				print_s(char *str, t_info *info);

char			*ft_baseset(char type);
int				print_num(signed long long num, t_info *info);
int				p_type(char **tmp);
int				put_prec(unsigned long long num, t_info *info, char **tmp);
int				put_minus_with_zero(t_info *info, char **tmp, int len);
int				put_minus(t_info *info, char **tmp);

int				ft_printf(const char *format, ...);
int				parsing_format(va_list ap, char *format);
void			width_prec_check(va_list ap, char *format, t_info *info, int i);
void			flag_check(va_list ap, t_info *info, char *format, int i);
int				print_type(va_list ap, t_info *info);

void			info_value(t_info *info);
int				ft_numlen(unsigned long long nbr, t_info *info);
char			*ft_baseset(char type);

char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strchr(const char *str, int c);
void			*ft_memmove(void *dest, const void *src, size_t num);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);

#endif
