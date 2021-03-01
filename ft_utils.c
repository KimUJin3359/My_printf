#include "ft_h.h"

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_sub_precision(t_options **op, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	if (n < 0)
	{
		(*op)->minus_dot = 1;
		return ;
	}
	(*op)->dot = n;
}

char	*ft_get_addr(long long addr, int s_len)
{
	char	*buf;
	int		i;

	i = s_len - 1;
	if (s_len < 3)
		s_len = 3;
	if (!(buf = (char *)malloc(sizeof(char) * s_len)))
		return (NULL);
	buf[0] = '0';
	buf[1] = 'x';
	if (s_len < 3)
		buf[2] = '0';
	while (i > 1)
	{
		buf[i] = HEX_S[(addr % 16)];
		addr /= 16;
		i--;
	}
	return (buf);
}

int		ft_get_size(t_options op, long long n)
{
	int			size;
	long long	num;

	size = 0;
	if (op.dot == 0 && n == 0)
		return (0);
	if (op.type == 'd' || op.type == 'i')
	{
		num = (int)n;
		if (num < 0)
		{
			size++;
			num = -num;
		}
		while (num /= 10)
			size++;
	}
	else if (op.type == 'u')
		while (n /= 10)
			size++;
	else
		while (n /= 16)
			size++;
	size++;
	return (size);
}

void	ft_putnbr(t_options op, unsigned int n, int s_len)
{
	char		c;
	char		*s;
	long long	num;

	if (s_len <= 0)
		return ;
	if (op.type == 'i' || op.type == 'd' || op.type == 'u')
		s = DEC;
	else if (op.type == 'X')
		s = HEX_B;
	else
		s = HEX_S;
	if (op.type == 'i' || op.type == 'd')
		num = (int)n;
	else
		num = n;
	if (num < 0 && s_len--)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (--s_len)
		ft_putnbr(op, (num / (long long)ft_strlen(s)), s_len);
	c = s[(int)(num % (long long)ft_strlen(s))];
	write(1, &c, 1);
}
