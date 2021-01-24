/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:00:00 by woojikim          #+#    #+#             */
/*   Updated: 2020/12/30 15:37:59 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void		ft_initialize_option(t_options *op)
{
	op->minus = 0;
	op->zero = 0;
	op->width = 0;
	op->dot = -1;
	op->only_dot = 0;
	op->minus_dot = 0;
	op->type = 0;
}

const char	*ft_check_flag(const char *s, t_options *op)
{
	s++;
	while (*s == '0' || *s == '-')
	{
		if (*s == '0')
			op->zero = 1;
		else
			op->minus = 1;
		s++;
	}
	return (s);
}

const char	*ft_check_width(const char *s, t_options *op, va_list ap)
{
	int n;
	if (*s == '*')
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			n = -n;
			op->minus = 1;
		}
		op->width = n;
		s++;
	}
	else if (*s >= '0' && *s <= '9')
	{
		while (*s >= '0' && *s <= '9')
		{
			op->width = (op->width * 10);
			op->width += (*s - '0');
			s++;
		}
	}
	return (s);
}

const char	*ft_check_precision(const char *s, t_options *op, va_list ap)
{
	if (*s == '.')
	{
		op->dot = 0;
		s++;
		if (*s == '*')
		{
			op->dot = -1;
			ft_sub_precision(&op, ap);
			s++;
		}
		else if (*s == '0')
			s++;
		else if (*s >= '1' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9')
			{
				op->dot = (op->dot * 10);
				op->dot += (*s - '0');
				s++;
			}
		}
		else
			op->only_dot = 1;
	}
	return (s);
}

const char	*ft_check_type(const char *s, t_options *op)
{
	if (*s == '%' || *s == 'c' || *s == 's'
		|| *s == 'p' || *s == 'd' || *s == 'i'
		|| *s == 'u' || *s == 'x' || *s == 'X')
	{
		op->type = (int)(*s);
		s++;
		return (s);
	}
	else
		return (NULL);
}
