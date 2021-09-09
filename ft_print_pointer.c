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
	int		chars;
	size_t	number_aux;

	chars = 1;
	number_aux = (size_t) pointer;
	if (!number_aux)
		chars = 3;
	else
		while (++chars && number_aux)
			number_aux /= 16;
	if (!ft_has_minus_flag(formaters[0]))
	{
		if (!ft_has_zero_flag(formaters[0]))
			chars += ft_put_n_char(' ', formaters[1] - chars);
		write(1, "0x", 2);
		if (ft_has_zero_flag(formaters[0]))
			chars += ft_put_n_char('0', formaters[1] - chars);
	}
	else
		write(1, "0x", 2);
	ft_print_hexadecimal_aux((size_t) pointer, HEX_LOWER);
	if (ft_has_minus_flag(formaters[0]))
		chars += ft_put_n_char(' ', formaters[1] - chars);
	return (chars);
}
