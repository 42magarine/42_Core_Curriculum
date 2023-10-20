/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:18:41 by mott              #+#    #+#             */
/*   Updated: 2023/10/20 18:13:33 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

# include "libft/libft.h"
# include <stdio.h> // remove
# include <limits.h> // remove
# include <ctype.h> // remove
# include <string.h> // remove

# define FLAG_MINUS	0x01 // 0000 0001
# define FLAG_ZERO	0x02 // 0000 0010
# define FLAG_DOT	0x04 // 0000 0100
# define FLAG_HASH	0x08 // 0000 1000
# define FLAG_SPACE	0x10 // 0001 0000
# define FLAG_PLUS	0x20 // 0010 0000

int	ft_printf(const char *format, ...);
int	ft_conversion_specifiers(const char *format, va_list *ap);

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
// int	ft_putunbr(unsigned int n);
int	ft_putnbr_base(unsigned long n, unsigned long base, bool lower);
int	ft_putnbr_base16(unsigned long n, char xp);

// int	ft_toupper(int c); // remove

#endif
