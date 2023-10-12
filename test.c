/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:22:44 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/12 16:07:12 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("%i\n", ft_printf("Hallo\n"));
	ft_printf("\n");
	ft_printf("%i\n", ft_printf("%i\n", 123));
	ft_printf("\n");
	/* ft_printf("%i\n", ft_printf("Hallo %% %c %i %i %s\n", 'c', 123, -123,
			"Welt")); */
	ft_printf("%i\n", ft_printf("Hallo %%\n"));
	ft_printf("%i\n", ft_printf("Hallo %c\n", 'c'));
	ft_printf("%i\n", ft_printf("Hallo %i\n", 123));
	ft_printf("%i\n", ft_printf("Hallo %i\n", -123));
	ft_printf("%i\n", ft_printf("Hallo %s\n", "Welt"));
	ft_printf("%i\n", ft_printf("Hallo %s\n", NULL));
	ft_printf("%i\n", ft_printf("Hallo %u\n", 123));
	ft_printf("%i\n", ft_printf("Hallo %u\n", 4294967296));
	ft_printf("%i\n", ft_printf("Hallo %u\n", 4294967295));
	ft_printf("%i\n", ft_printf("Hallo %x\n", 255));
	ft_printf("%i\n", ft_printf("Hallo %x\n", -255));
	ft_printf("%i\n", ft_printf("Hallo %X\n", 255));
	ft_printf("%i\n", ft_printf("Hallo %X\n", -255));
	ft_printf("%i\n", ft_printf("Hallo %p\n", LONG_MIN));
	printf("%i\n", printf("Hallo %p\n", (void *)LONG_MIN));
	ft_printf("%i\n", ft_printf("Hallo %p\n", LONG_MAX));
	printf("%i\n", printf("Hallo %p\n", (void *)LONG_MAX));
	ft_printf("%i\n", ft_printf("Hallo %p\n", ULONG_MAX));
	printf("%i\n", printf("Hallo %p\n", (void *)ULONG_MAX));
	ft_printf("%i\n", ft_printf("Hallo %p\n", -ULONG_MAX));
	printf("%i\n", printf("Hallo %p\n", (void *)-ULONG_MAX));

	/* printf("%i\n", printf("Hallo\n"));
	printf("\n");
	printf("%i\n", printf("%i\n", 123));
	printf("\n");
	printf("%i\n", printf("Hallo %%\n"));
	printf("%i\n", printf("Hallo %c\n", 'c'));
	printf("%i\n", printf("Hallo %i\n", 123));
	printf("%i\n", printf("Hallo %i\n", -123));
	printf("%i\n", printf("Hallo %s\n", "Welt"));
	printf("%i\n", printf("Hallo %s\n", NULL));
	printf("%i\n", printf("Hallo %u\n", 123));
	printf("%i\n", printf("Hallo %x\n", 255));
	printf("%i\n", printf("Hallo %x\n", -255));
	printf("%i\n", printf("Hallo %X\n", 255));
	printf("%i\n", printf("Hallo %X\n", -255)); */
	return (0);
}