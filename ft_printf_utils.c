/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:45:49 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:45:49 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_n_char(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}

int	ft_print_unsigned_int_aux(size_t number)
{
	char	c;
	int		chars;

	if (number > 9)
	{
		chars = ft_print_unsigned_int_aux(number / 10);
		c = (number % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		chars = 0;
		c = number + '0';
		write(1, &c, 1);
	}
	return (1 + chars);
}

int	ft_print_hexadecimal_aux(size_t number, char *base)
{
	char	c;
	int		chars;

	if (number > 15)
	{
		chars = ft_print_hexadecimal_aux(number / 16, base);
		c = base[number % 16];
		write(1, &c, 1);
	}
	else
	{
		chars = 0;
		c = base[number];
		write(1, &c, 1);
	}
	return (1 + chars);
}
