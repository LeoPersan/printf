/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:47:43 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/21 09:54:15 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_formater	*calc_formaters(long long number, t_formater *formaters)
{
	long long	number_aux;

	number_aux = number;
	formaters->chars = -1;
	while (!(++formaters->chars) || number_aux)
		number_aux /= 10;
	if (number < 0 || ft_has_plus_flag(formaters->flags))
		formaters->prefix = 1;
	formaters->before_zeros = formaters->precision - formaters->chars;
	if (formaters->before_zeros < 0)
		formaters->before_zeros = 0;
	number_aux = formaters->width - formaters->before_zeros;
	number_aux = number_aux - formaters->chars - formaters->prefix;
	if (ft_has_minus_flag(formaters->flags))
		formaters->after_spaces = number_aux;
	else if (ft_has_zero_flag(formaters->flags) && formaters->precision < 0
		&& formaters->width > 0)
		formaters->before_zeros = number_aux;
	else
		formaters->before_spaces = number_aux;
	if (ft_has_space_flag(formaters->flags) && !formaters->prefix)
		formaters->before_spaces = 1;
	return (formaters);
}

int	ft_print_int(long long number, t_formater *formaters)
{
	int	width;

	width = 0;
	formaters = calc_formaters(number, formaters);
	width += ft_put_n_char(' ', formaters->before_spaces);
	if (number < 0)
		width += (write(1, "-", 1));
	else if (ft_has_plus_flag(formaters->flags))
		width += (write(1, "+", 1));
	width += ft_put_n_char('0', formaters->before_zeros);
	if (number < 0)
		number *= -1;
	if (formaters->precision != 0 || number != 0)
		width += ft_print_unsigned_int_aux(number);
	else if (formaters->width != 0)
		width += write(1, " ", 1);
	width += ft_put_n_char(' ', formaters->after_spaces);
	return (width);
}
