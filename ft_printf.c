#include "ft_h.h"

int		ft_print_arg(t_options op, va_list ap)
{
	int len;

	len = 0;
	if (op.type == '%')
		len = ft_print_percent(op);
	else if (op.type == 'c')
		len = ft_print_char(op, ap);
	else if (op.type == 's')
		len = ft_print_str(op, ap);
	else if (op.type == 'p')
		len = ft_print_addr(op, ap);
	else
		len = ft_print_nbr(op, ap);
	return (len);
}

int		ft_print(const char *format, va_list ap, t_options op, int len)
{
	int			res;
	char		*s;

	s = (char *)format;
	while (*s)
	{
		ft_initialize_option(&op);
		if (*s != '%')
		{
			len += write(1, s, 1);
			s++;
		}
		else
		{
			s = (char *)ft_check_flag(s, &op);
			s = (char *)ft_check_width(s, &op, ap);
			s = (char *)ft_check_precision(s, &op, ap);
			if (!(s = (char *)ft_check_type(s, &op)))
				return (-1);
			if ((res = ft_print_arg(op, ap)) == -1)
				return (-1);
			len += res;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	op;
	int			res;

	res = 0;
	ft_initialize_option(&op);
	va_start(ap, format);
	res = ft_print(format, ap, op, res);
	va_end(ap);
	return (res);
}
