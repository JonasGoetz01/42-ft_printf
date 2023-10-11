/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/11 10:07:08 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_switch_format(va_list args, const char c, int *ret)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		return (ft_strlen(va_arg(args, char *)));
	}
	else if (c == 'p')
	{
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	}
	else if (c == 'd||i')
	{
		ft_putstr_fd(ft_itoa(va_arg(args, char *)), 1);
		return (ft_strlen(ft_itoa(va_arg(args, char *))));
	}
	else if (c == 'u')
	{
		return (ft_print_udec());
	}
	else if (c == 'x||X')
	{
		if (c == 'x')
			return (ft_print_lhex(va_arg(args, int)));
		else if (c == 'X')
			return (ft_print_uhex(va_arg(args, int)));
	}
	else if (c == '%')
	{
	}
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	args;
	int		i;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_switch_format(args, str[i + 1], &ret);
			i++;
		}
		else
		{
			ret += 1;
			ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (ret);
}
