/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:48:47 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:48:47 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *pointer, int *formaters)
{
	int		width;
	int		chars;
	size_t	number_aux;

	chars = 0;
	number_aux = (size_t) pointer;
	if (!number_aux)
		return (write(1, "(nil)", 5));
	while (number_aux)
	{
		number_aux /= 16;
		chars++;
	}
	width = 2;
	if (!ft_has_minus_flag(formaters[0]))
	{
		if (!ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		write(1, "0x", 2);
		if (ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char('0', formaters[1] - width - chars);
	}
	else
		write(1, "0x", 2);
	ft_print_hexadecimal_aux((size_t) pointer, HEX_LOWER);
	if (ft_has_minus_flag(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}
