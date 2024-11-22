/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexbased.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkasap <fkasap@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:27:19 by fkasap            #+#    #+#             */
/*   Updated: 2024/11/22 17:38:54 by fkasap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puthex(unsigned int i, const char c)
{
	int	len;

	len = 0;
	if (i >= 16)
	{
		len += ft_puthex (i / 16, c);
		len += ft_puthex (i % 16, c);
	}
	else
	{
		if (c == 'x')
		{
			if (write(1, &"0123456789abcdef"[i], 1) == -1)
				return (-1);
		}
		else if (c == 'X')
		{
			if (write(1, &"0123456789ABCDEF"[i], 1) == -1)
				return (-1);
		}
		len++;
	}
	return (len);
}

int	ft_putptr(unsigned long p)
{
	int				len;
	int				tmp1;
	int				tmp2;
	unsigned int	high_part;
	unsigned int	low_part;

	len = 0;
	if (p == 0)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	high_part = (unsigned int)(p >> 32);
	low_part = (unsigned int)(p & 0xFFFFFFFF);
	tmp1 = 0;
	if (high_part != 0)
		tmp1 = ft_puthex(high_part, 'x');
	tmp2 = ft_puthex(low_part, 'x');
	if (tmp1 == -1 || tmp2 == -1)
		return (-1);
	len += tmp1 + tmp2;
	return (len);
}
