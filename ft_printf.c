/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkasap <fkasap@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:42:33 by fkasap            #+#    #+#             */
/*   Updated: 2024/11/22 17:08:32 by fkasap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
    va_list	vl;
    int		i;
    int		w_len;
	int		error_check;

	i = -1;
	w_len = 0;
    va_start(vl, s);
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			error_check = ft_type(vl, s[++i]);
			if (error_check == -1)
				return (-1);
			w_len += error_check - 1;
		}
		else if (ft_putchar(s[i]) == -1)
			return (-1);
		w_len++;
	}
    va_end(vl);
	return (w_len);
}

int	ft_type(va_list vl, const char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(vl, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vl, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(vl, unsigned long)));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(vl, unsigned int), type));
	else if (type =='d' || type == 'i')
		return (ft_putnbr(va_arg(vl, int)));
	else if (type == 'u')
		return (ft_putuns_nbr(va_arg(vl, unsigned int)));
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
