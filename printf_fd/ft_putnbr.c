/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:01:47 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/27 09:53:30 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int fd)
{
	int				count;
	unsigned int	num;

	num = n;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-', fd);
		num = -n;
	}
	if (num < 10)
		count += ft_putchar(num + '0', fd);
	else
	{
		count += ft_putnbr(num / 10, fd);
		count += ft_putnbr(num % 10, fd);
	}
	return (count);
}
