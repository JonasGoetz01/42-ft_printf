/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/12 17:44:23 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_hex_digits(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

static int	ft_hex(unsigned long n, char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		if (n >= 16)
		{
			ft_print_hex(n / 16, format);
			ft_print_hex(n % 16, format);
		}
		else
		{
			if (n < 10)
				ft_putchar_fd((n + '0'), 1);
			else
			{
				if (format == 'x')
					ft_putchar_fd((n - 10 + 'a'), 1);
				if (format == 'X')
					ft_putchar_fd((n - 10 + 'A'), 1);
			}
		}
	}
	return (num_hex_digits(n));
}

int	ft_print_ptr(unsigned long n, char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		if (n >= 16)
		{
			ft_hex(n / 16, format);
			ft_hex(n % 16, format);
		}
		else
		{
			if (n < 10)
				ft_putchar_fd((n + '0'), 1);
			else
			{
				if (format == 'x')
					ft_putchar_fd((n - 10 + 'a'), 1);
				if (format == 'X')
					ft_putchar_fd((n - 10 + 'A'), 1);
			}
		}
	}
	return (num_hex_digits(n));
}