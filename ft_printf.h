/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/11 13:38:29 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_udec(unsigned int n);
int	ft_print_percent(void);
int	ft_print_int(int n);
int	get_num_udigits(unsigned int n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_ptr(unsigned long long ptr);
int	ft_putstr(char *str);
int	ft_print_char(int c);
int	put_unsigned_nbr(unsigned int num);
int	put_nbr(int num);

#endif