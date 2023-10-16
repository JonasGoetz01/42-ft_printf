/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/16 16:55:18 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_udigits(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_print_udec(unsigned int n)
{
	char	digit;

	if (n > 9)
		if (ft_print_udec(n / 10) == -1)
			return (-1);
	digit = '0' + n % 10;
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (0);
}

static int	ft_put_unsigned_nbr(unsigned int n)
{
	char	c;
	int		len;
	int		i;

	len = 0;
	if (n >= 10)
	{
		i = ft_put_unsigned_nbr(n / 10);
		if (i == -1)
			return (-1);
		len += i;
	}
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	put_unsigned_nbr(unsigned int num)
{
	int	len;

	len = ft_put_unsigned_nbr(num);
	if (len == -1)
		return (-1);
	return (len);
}
