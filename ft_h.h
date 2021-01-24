/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:50:34 by woojikim          #+#    #+#             */
/*   Updated: 2020/12/30 15:27:54 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# define HEX_B "0123456789ABCDEF"
# define HEX_S "0123456789abcdef"
# define DEC "0123456789"
# define STR "(null)"
# define STR_N ""

# include "stdlib.h"
# include "unistd.h"
# include "stdarg.h"
# include "stdio.h"

typedef struct				s_options
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int only_dot;
	int	minus_dot;
	int	type;
}							t_options;

int							ft_print_arg(t_options op, va_list ap);
int							ft_print(const char *format, va_list ap,
							t_options op, int len);
int							ft_printf(const char *format, ...);

void						ft_initialize_option(t_options *op);
const char					*ft_check_flag(const char *s, t_options *op);
const char					*ft_check_width(const char *s,
							t_options *op, va_list ap);
const char					*ft_check_precision(const char *s,
							t_options *op, va_list ap);
const char					*ft_check_type(const char *s, t_options *op);

int							ft_print_percent(t_options op);
int							ft_print_char(t_options op, va_list ap);
int							ft_print_str(t_options op, va_list ap);
int							ft_print_addr(t_options op, va_list ap);
int							ft_print_nbr(t_options op, va_list ap);

size_t						ft_strlen(char *s);
void						ft_sub_precision(t_options **op, va_list ap);
char						*ft_get_addr(long long addr, int s_len);
int							ft_get_size(t_options op, long long n);
void						ft_putnbr(t_options op, unsigned int n, int s_len);

#endif
