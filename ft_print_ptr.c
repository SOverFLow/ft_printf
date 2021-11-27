/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:47:58 by selhanda          #+#    #+#             */
/*   Updated: 2021/11/23 16:04:00 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

int	ft_len_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_put_char(ptr + '0');
		else
			ft_put_char(ptr - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_len;

	write(1, "0x", 2);
	print_len = 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		print_len++;
	}
	else
	{
		ft_put_ptr(ptr);
		print_len += ft_len_ptr(ptr);
	}
	return (print_len);
}
