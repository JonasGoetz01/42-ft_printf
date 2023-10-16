/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/16 14:43:55 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_hex_digits(unsigned int n)
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

int	ft_print_hex(unsigned int n, char format)
{
	char	c;

	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		if (n >= 16)
		{
			if (ft_print_hex(n / 16, format) == -1)
				return (-1);
			if (ft_print_hex(n % 16, format) == -1)
				return (-1);
		}
		else
		{
			if (n < 10)
			{
				c = (n + '0');
				if (write(1, &c, 1) == -1)
					return (-1);
			}
			else
			{
				if (format == 'x')
				{
					c = (n - 10 + 'a');
					if (write(1, &c, 1) == -1)
						return (-1);
				}
				if (format == 'X')
				{
					c = (n - 10 + 'A');
					if (write(1, &c, 1) == -1)
						return (-1);
				}
			}
		}
	}
	return (num_hex_digits(n));
}
