/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/16 12:27:30 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_hex(uintptr_t n)
{
	char	c;

	if (n >= 16)
	{
		ft_hex(n / 16);
		ft_hex(n % 16);
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
			c = (n - 10 + 'a');
			if (write(1, &c, 1) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	ret;

	ret = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret += 2;
	if (ptr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		ret += 1;
	}
	else
	{
		if (ft_hex(ptr) == -1)
			return (-1);
		ret += ft_ptr_len(ptr);
	}
	return (ret);
}
