/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:08 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/27 09:55:56 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_putnbr(int n, int fd);
int	ft_putchar(char c, int fd);
int	ft_printf_hex(unsigned int n, char *symbols, int fd);
int	ft_printf_add(unsigned long address, char *symbols, int flag, int fd);
int	ft_printf_uns(unsigned int n, int fd);
int	ft_putstr(char *str, int fd);
#endif
