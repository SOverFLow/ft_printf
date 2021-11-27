/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:57:23 by selhanda          #+#    #+#             */
/*   Updated: 2021/11/23 17:18:58 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *s);
char	*ft_itoa(int n);
int		ft_print_percent(void);
int		ft_print_nbr(int n);
void	ft_putstr(char *s);
char	*ft_uitoa(unsigned int n);
int		ft_print_unbr(unsigned int n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_hex(unsigned int num, char const format);

#endif
