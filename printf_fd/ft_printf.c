/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:18:21 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/28 09:58:01 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char format, va_list ap, int fd)
{
	int	num;

	num = 0;
	if (format == '%')
		num += ft_putchar('%', fd);
	else if (format == 'c')
		num += ft_putchar(va_arg(ap, int), fd);
	else if (format == 's')
		num += ft_putstr(va_arg(ap, void *), fd);
	else if (format == 'i' || format == 'd')
		num += ft_putnbr(va_arg(ap, int), fd);
	else if (format == 'u')
		num += ft_printf_uns(va_arg(ap, unsigned int), fd);
	else if (format == 'x')
		num += ft_printf_hex(va_arg(ap, unsigned int), "0123456789abcdef", fd);
	else if (format == 'X')
		num += ft_printf_hex(va_arg(ap, unsigned int), "0123456789ABCDEF", fd);
	else if (format == 'p')
		num += ft_printf_add(va_arg(ap, unsigned long),
				"0123456789abcdef", 0, fd);
	else
		return (0);
	return (num);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list		ap;
	int			counter;

	counter = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
			counter += print_format(*(++format), ap, fd);
		else
			counter += ft_putchar(*format, fd);
		format++;
	}
	va_end (ap);
	return (counter);
}
