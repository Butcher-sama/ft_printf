/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexbased.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkasap <fkasap@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:27:19 by fkasap            #+#    #+#             */
/*   Updated: 2024/11/25 17:58:02 by fkasap           ###   ########.fr       */
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

static int	ft_putptr_hex(unsigned long i)
{
	int	len;

	len = 0;
	if (i >= 16)
	{
		len += ft_putptr_hex (i / 16);
		len += ft_putptr_hex (i % 16);
	}
	else
	{
		if (write(1, &"0123456789abcdef"[i], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putptr(unsigned long p)
{
	int	len;
	int	tmp;

	len = 0;
	if (p == 0)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	tmp = ft_putptr_hex(p);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
