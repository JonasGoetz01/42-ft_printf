/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/11 10:50:36 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_switch_format(va_list args, const char c, int *ret)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, char), 1);
		*ret += (1);
	}
	else if (c == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		*ret += (ft_strlen(va_arg(args, char *)));
	}
	else if (c == 'p')
	{
		*ret += (ft_print_ptr(va_arg(args, unsigned long long)));
	}
	else if (c == 'd' || c == 'i')
	{
		ft_putstr_fd(ft_itoa(va_arg(args, char *)), 1);
		*ret += (ft_strlen(ft_itoa(va_arg(args, char *))));
	}
	else if (c == 'u')
	{
		*ret += (ft_print_udec(va_arg(args, int)));
	}
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			*ret += (ft_print_lhex(va_arg(args, int)));
		else if (c == 'X')
			*ret += (ft_print_uhex(va_arg(args, int)));
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
			ft_switch_format(args, str[i + 1], &ret);
			i++;
		}
		else
		{
			ret += 1;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (ret);
}
