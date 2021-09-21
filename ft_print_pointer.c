/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:48:47 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/21 08:18:33 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_formater	*calc_formaters(size_t pointer, t_formater *formaters)
{
	size_t	number_aux;

	number_aux = pointer;
	formaters->chars = -1;
	while (!(++formaters->chars) || number_aux)
		number_aux /= 16;
	formaters->prefix = 2;
	number_aux = formaters->width - formaters->chars - formaters->prefix;
	if (ft_has_zero_flag(formaters->flags))
		formaters->before_zeros = number_aux;
	else if (ft_has_minus_flag(formaters->flags))
		formaters->after_spaces = number_aux;
	else
		formaters->before_spaces = number_aux;
	return (formaters);
}

int	ft_print_pointer(void *pointer, t_formater *formaters)
{
	int	width;

	width = 0;
	formaters = calc_formaters((size_t) pointer, formaters);
	width += ft_put_n_char(' ', formaters->before_spaces);
	width += write(1, "0x", 2);
	width += ft_put_n_char('0', formaters->before_zeros);
	width += ft_print_hexadecimal_aux((size_t) pointer, HEX_LOWER);
	width += ft_put_n_char(' ', formaters->after_spaces);
	return (width);
}
