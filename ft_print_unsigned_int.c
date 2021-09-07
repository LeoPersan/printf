/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:47:19 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:47:19 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(unsigned int number, int *formaters)
{
	int				width;
	int				chars;
	unsigned int	number_aux;

	chars = 0;
	number_aux = number;
	while (!chars || number_aux)
	{
		number_aux /= 10;
		chars++;
	}
	width = 0;
	if (!ft_has_minus_flag(formaters[0]))
	{
		if (formaters[2] > -1 && formaters[2] + chars < formaters[1])
			formaters[1] -= formaters[2] - chars;
		if (!ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		if (ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char('0', formaters[1] - width - chars);
		while (formaters[2] > -1 && chars < formaters[2])
		{
			chars++;
			write(1, "0", 1);
		}
	}
	ft_print_unsigned_int_aux(number);
	if (ft_has_minus_flag(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}
