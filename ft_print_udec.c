/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/16 10:34:13 by jgotz            ###   ########.fr       */
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
