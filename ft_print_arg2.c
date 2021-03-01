#include "ft_h.h"

int		ft_print_str_sub(t_options op, char *s, int size, int s_len)
{
	int		i;
	int		j;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * size)))
		return (-1);
	i = -1;
	if (op.minus)
	{
		while (++i < s_len)
			res[i] = s[i];
		while (i < size)
			res[i++] = ' ';
	}
	else
	{
		j = 0;
		while (++i < size - s_len)
			res[i] = ' ';
		while (j < s_len)
			res[i++] = s[j++];
	}
	write(1, res, size);
	free(res);
	return (size);
}

int		ft_print_str(t_options op, va_list ap)
{
	int		s_len;
	int		size;
	int		flag;
	char	*s;

	flag = 0;
	if (op.zero)
		return (-1);
	s = va_arg(ap, char *);
	if (!s)
		s = STR;
	if (op.dot != -1)
		s_len = ((int)ft_strlen(s) > op.dot) ? op.dot : ft_strlen(s);
	else
		s_len = ft_strlen(s);
	size = (s_len > op.width) ? s_len : op.width;
	return (ft_print_str_sub(op, s, size, s_len));
}

void	ft_print_nbr_sub(t_options op, int s_len, int size, int n)
{
	int s_len_buf;

	if (op.zero)
	{
		s_len = size;
		ft_putnbr(op, n, s_len);
	}
	else
	{
		s_len_buf = s_len;
		while (s_len++ < size)
			write(1, " ", 1);
		ft_putnbr(op, n, s_len_buf);
	}
}

int		ft_print_nbr(t_options op, va_list ap)
{
	unsigned int		n;
	int					s_len;
	int					size;
	char				*res;

	n = va_arg(ap, int);
	if (op.dot != -1 && op.zero)
		op.zero = 0;
	if ((op.type == 'd' || op.type == 'i') && (int)n < 0)
		op.dot++;
	s_len = (ft_get_size(op, n) > op.dot) ?
			ft_get_size(op, (long long)n) : op.dot;
	size = (s_len > op.width) ? s_len : op.width;
	if (!(res = (char *)malloc(sizeof(char) * size)))
		return (-1);
	if (op.minus)
	{
		ft_putnbr(op, n, s_len);
		while (s_len++ < size)
			write(1, " ", 1);
	}
	else
		ft_print_nbr_sub(op, s_len, size, n);
	return (size);
}
