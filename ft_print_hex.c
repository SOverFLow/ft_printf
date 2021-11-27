/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:09:35 by selhanda          #+#    #+#             */
/*   Updated: 2021/11/23 17:00:34 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char_hex(char c)
{
	write(1, &c, 1);
}

int	ft_len_hex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, char const format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_put_char_hex(num + '0');
		else
		{
			if (format == 'x')
				ft_put_char_hex(num - 10 + 'a');
			else if (format == 'X')
				ft_put_char_hex(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, char const format)
{
	int	print_len;

	print_len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		print_len++;
	}
	else
	{
		ft_put_hex(num, format);
		print_len += ft_len_hex(num);
	}
	return (print_len);
}
