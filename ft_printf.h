/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:18:41 by mott              #+#    #+#             */
/*   Updated: 2023/10/25 16:54:30 by mott             ###   ########.fr       */
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

typedef struct s_flags
{
	bool	alternate_form;			// Indicates whether the '#' flag is set.
	bool	zero_padded;			// Indicates whether the '0' flag is set.
	bool	left_adjusted;			// Indicates whether the '-' flag is set.
	bool	space_sign;				// Indicates whether the ' ' flag is set.
	bool	plus_sign;				// Indicates whether the '+' flag is set.
	bool	field_width_argument;	// Indicates whether the field width is specified as an argument using the '*' flag.
	int		field_width_value;		// Stores the value of the field width.
	bool	precision;				// Indicates whether precision is specified using the '.' flag.
	int		precision_value;		// Stores the value of precision.
}	t_flags;

int	ft_printf(const char *format, ...);
int	ft_conversion_specifiers(va_list *ap, const char *format, t_flags *flags);

int	ft_putchar(int c);
int	ft_putstr(char *s, int str_len);
int	ft_putnbr(long n);
int	ft_putnbr_base(unsigned long n, unsigned long base, bool lower);
int	ft_putnbr_base16(unsigned long n, char xp);

const char	*ft_flags(va_list *ap, const char *format, t_flags *flags);
int	ft_isflag(int c);
int	prepare_c(int c, t_flags *flags);
int	prepare_s(char *s, t_flags *flags);
int	field_width(t_flags *flags, int length);

int	ft_toupper(int c); // remove
int	ft_isdigit(int c); // remove
size_t	ft_strlen(const char *s); // remove

#endif
