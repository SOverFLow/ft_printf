/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:33:05 by selhanda          #+#    #+#             */
/*   Updated: 2021/11/23 13:57:55 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_ustr(int i, unsigned long temp, char *str, unsigned int n)
{
	while (temp >= 10)
	{
		temp = temp / 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (--i >= 0 && n != 0)
	{
		str[i] = 1 * (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 1;
	str = NULL;
	temp = n;
	return (ft_check_ustr(i, temp, str, n));
}

int	ft_print_unbr(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_uitoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}
