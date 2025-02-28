/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:45:00 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/27 09:54:07 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_add(unsigned long address, char *symbols, int flag, int fd)
{
	int	count;

	count = 0;
	if (flag == 0)
	{
		count += ft_putstr("0x", fd);
		flag = 1;
	}
	if (address < 16)
		count += ft_putchar(symbols[address], fd);
	else
	{
		count += ft_printf_add(address / 16, symbols, flag, fd);
		count += ft_printf_add(address % 16, symbols, flag, fd);
	}
	return (count);
}
