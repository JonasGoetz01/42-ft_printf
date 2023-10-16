/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/16 14:34:30 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_dynamic_memory(void *ptr)
{
	return (ptr > (void *)0x1000 && ptr < (void *)0x100000000);
}

int	get_num_digits(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	putnbr(long n)
{
	char	c;

	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (putnbr(n / 10) == -1)
			return (-1);
	}
	c = '0' + n % 10;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}

static int	ft_switch_format2(va_list args, const char c, int *ret)
{
	unsigned int	i;
	int				len;
	long			n;

	if (c == 'p')
	{
		len = ft_print_ptr(va_arg(args, unsigned long long));
		if (len == -1)
			return (-1);
		else
			*ret += len;
	}
	else if ((c == 'd') || (c == 'i'))
	{
		n = (long)va_arg(args, int);
		if (putnbr(n) == -1)
			return (-1);
		*ret += get_num_digits(n);
	}
	else if (c == 'u')
	{
		i = va_arg(args, unsigned int);
		if (ft_print_udec(i) == -1)
			return (-1);
		*ret += get_num_udigits(i);
	}
	else if ((c == 'x') || (c == 'X'))
	{
		len = ft_print_hex(va_arg(args, unsigned long), c);
		if (len == -1)
			return (-1);
		*ret += len;
	}
	else if (c == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		*ret += 1;
	}
	else
		return (-1);
	return (1);
}

static int	ft_switch_format(va_list args, const char c, int *ret)
{
	char	*str;
	char	cha;

	str = "";
	if (c == 'c')
	{
		cha = va_arg(args, int);
		if (write(1, &cha, 1) == -1)
			return (-1);
		*ret += (1);
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		if (ft_putstr(str) == -1)
			return (-1);
		*ret += (ft_strlen(str));
		if (is_dynamic_memory(str))
			free(str);
	}
	else
	{
		if (ft_switch_format2(args, c, ret) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int ret;
	va_list args;
	int i;

	i = 0;
	ret = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_switch_format(args, str[i + 1], &ret) == -1)
				return (-1);
			i++;
		}
		else
		{
			ret += 1;
			if (write(1, &str[i], 1) == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (ret);
}