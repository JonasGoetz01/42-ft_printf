/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/11 00:57:36 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	return ((int)ft_strlen(str));
	/* va_list args;
	int i;
	int ret;

	i = 0;
	while (str[i])
	{
		if(str[i] == '%')
		{

		}
		else
		{
			ret += ft_strlen();
		}
		i++;
	} */
}