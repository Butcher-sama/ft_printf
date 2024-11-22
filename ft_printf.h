/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkasap <fkasap@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:18:25 by fkasap            #+#    #+#             */
/*   Updated: 2024/11/12 23:34:04 by fkasap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_type(va_list vl, const char type);
int	ft_putchar(int c);
int ft_putstr(char *s);
int	ft_puthex(unsigned int i, const char c);
int	ft_putptr(unsigned long p);
int ft_putnbr(int i);
int ft_putuns_nbr(unsigned int i);

#endif