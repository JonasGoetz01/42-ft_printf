/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:50:26 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/10 19:59:30 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *, ...);
void	ft_print_uhex(char *str);
void	ft_print_udec(char *str);
void	ft_print_str(char *str);
void	ft_print_ptr(char *str);
void	ft_print_percent(char *str);
void	ft_print_percent(char *str);
void	ft_print_lhex(char *str);
void	ft_print_int(char *str);
void	ft_print_dec(char *str);
void	ft_print_char(char *str);

#endif LIBFTPRINTF_H