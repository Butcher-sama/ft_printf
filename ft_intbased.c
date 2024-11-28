/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intbased.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkasap <fkasap@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:20:01 by fkasap            #+#    #+#             */
/*   Updated: 2024/11/25 17:53:07 by fkasap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int i)
{
	int	len;
	int	nb;

	len = 0;
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		i *= -1;
	}
	if (i > 9)
	{
		nb = ft_putnbr(i / 10);
		if (nb == -1)
			return (-1);
		len += nb;
	}
	if (write(1, &("0123456789"[i % 10]), 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putuns_nbr(unsigned int i)
{
	unsigned int	len;
	int				nb;

	len = 0;
	if (i > 9)
	{
		nb = ft_putuns_nbr(i / 10);
		if (nb == -1)
			return (-1);
		len += nb;
	}
	if (write(1, &("0123456789"[i % 10]), 1) == -1)
		return (-1);
	return (len + 1);
}
