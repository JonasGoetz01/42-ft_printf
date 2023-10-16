/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/16 17:12:43 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_dynamic_memory(void *ptr)
{
	return (ptr > (void *)0x1000 && ptr < (void *)0x100000000);
}

static int	ft_handle_format(va_list args, const char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (put_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (put_unsigned_nbr(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_print_char('%'));
	else
		return (-1);
}

static int	printf_helper(const char *str, int *i, va_list args)
{
	int	l;

	l = 0;
	if (str[*i] == '%')
	{
		l = ft_handle_format(args, str[(*i) + 1]);
		if (l == -1)
			return (-1);
		(*i)++;
	}
	else
	{
		if (write(1, &str[*i], 1) == -1)
			return (-1);
		l = 1;
	}
	(*i)++;
	return (l);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;
	int		i;
	int		len;
	int		l;

	ret = 0;
	i = 0;
	len = 0;
	l = 0;
	va_start(args, str);
	while (str[i])
	{
		l = printf_helper(str, &i, args);
		if (l == -1)
		{
			va_end(args);
			return (-1);
		}
		len += l;
	}
	va_end(args);
	return (len);
}
