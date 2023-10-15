/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/13 10:57:22 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_dynamic_memory(void *ptr)
{
	return (ptr > (void *)0x1000 && ptr < (void *)0x100000000);
}

static void	ft_switch_format2(va_list args, const char c, int *ret)
{
	char			*str;
	unsigned int	i;

	if (c == 'p')
		*ret += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		ft_putstr_fd(str, 1);
		*ret += (ft_strlen(str));
		free(str);
	}
	else if (c == 'u')
	{
		i = va_arg(args, unsigned int);
		ft_print_udec(i);
		*ret += get_num_udigits(i);
	}
	else if (c == 'x' || c == 'X')
		*ret += (ft_print_hex(va_arg(args, unsigned long), c));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		*ret += 1;
	}
}

static void	ft_switch_format(va_list args, const char c, int *ret)
{
	char	*str;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		*ret += (1);
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		ft_putstr_fd(str, 1);
		*ret += (ft_strlen(str));
		if (is_dynamic_memory(str))
			free(str);
	}
	else
		ft_switch_format2(args, c, ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	args;
	int		i;

	i = 0;
	ret = 0;
	va_start(args, str);
	if (!str)
		return (-1);
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
