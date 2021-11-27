/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:55:08 by selhanda          #+#    #+#             */
/*   Updated: 2021/11/23 17:01:48 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(ap, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		print_len += ft_print_unbr(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		print_len += ft_print_percent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_format(ap, *str);
			str++;
		}
		else
		{
			len += ft_print_char(*str);
			str++;
		}
	}
	va_end(ap);
	return (len);
}
