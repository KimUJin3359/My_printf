/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:32:30 by woojikim          #+#    #+#             */
/*   Updated: 2020/12/30 15:39:43 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_print_percent(t_options op)
{
	char	*s;
	int		len;
	int		i;

	len = (op.width > 1) ? op.width : 1;
	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * (len))))
		return (-1);
	if (op.minus)
	{
		s[i] = '%';
		while (++i < len)
			s[i] = ' ';
	}
	else
	{
		while (i < len - 1)
			s[i++] = (op.zero) ? '0' : ' ';
		s[i] = '%';
	}
	write(1, s, len);
	free(s);
	return (len);
}

int		ft_print_char(t_options op, va_list ap)
{
	char	*s;
	int		len;
	int		i;

	if ((op.dot != -1 && op.only_dot == 0) || op.zero)
		return (-1);
	len = (op.width > 1) ? op.width : 1;
	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * (len))))
		return (-1);
	if (op.minus)
	{
		s[i] = va_arg(ap, int);
		while (++i < len)
			s[i] = ' ';
	}
	else
	{
		while (i < len - 1)
			s[i++] = ' ';
		s[i] = va_arg(ap, int);
	}
	write(1, s, len);
	free(s);
	return (len);
}

int		ft_print_addr_sub(t_options op, char *s, int len, int s_len)
{
	int		i;
	int		j;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * len)))
		return (-1);
	i = -1;
	if (op.minus)
	{
		while (++i < s_len)
			buf[i] = s[i];
		while (i < len)
			buf[i++] = ' ';
	}
	else
	{
		while (++i < len - s_len)
			buf[i] = ' ';
		j = 0;
		while (j < s_len)
			buf[i++] = s[j++];
	}
	write(1, buf, len);
	free(buf);
	return (len);
}

int		ft_print_addr(t_options op, va_list ap)
{
	long long	num;
	char		*s;
	int			len;
	int			s_len;

	if ((op.dot != -1 && op.only_dot == 0) || op.zero)
		return (-1);
	num = va_arg(ap, long long);
	s_len = ft_get_size(op, num) + 2;
	if (!(s = ft_get_addr(num, s_len)))
		return (-1);
	if (op.only_dot == 1 && num == 0)
		s_len = 2;
	else if (num == 0)
		s_len = 3;
	len = (op.width > s_len) ? op.width : s_len;
	ft_print_addr_sub(op, s, len, s_len);
	free(s);
	return (len);
}
