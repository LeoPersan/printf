/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:49 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/21 19:10:02 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_prefix(unsigned int number, char *base, int flags)
{
	if (!has_hashtag_flag(flags) || !number)
		return (0);
	if (base[10] == 'A')
		return (write(1, "0X", 2));
	return (write(1, "0x", 2));
}

static t_formater	*calc_formaters(unsigned int number, t_formater *formaters)
{
	size_t	number_aux;

	number_aux = number;
	formaters->chars = -1;
	while (!(++formaters->chars) || number_aux)
		number_aux /= 16;
	if (has_hashtag_flag(formaters->flags))
		formaters->prefix = 2;
	if (has_space_flag(formaters->flags) && !formaters->prefix)
		formaters->before_spaces = 1;
	formaters->before_zeros = formaters->precision - formaters->chars;
	if (formaters->before_zeros < 0)
		formaters->before_zeros = 0;
	number_aux = formaters->width - formaters->before_zeros;
	number_aux = number_aux - formaters->chars - formaters->prefix;
	if (has_minus_flag(formaters->flags))
		formaters->after_spaces = number_aux;
	else if (has_zero_flag(formaters->flags) && formaters->precision < 0
		&& formaters->width > 0)
		formaters->before_zeros = number_aux;
	else
		formaters->before_spaces = number_aux;
	return (formaters);
}

int	print_hexadecimal(unsigned int number, char *base, t_formater *formaters)
{
	int	width;

	width = 0;
	formaters = calc_formaters(number, formaters);
	width += put_n_char(' ', formaters->before_spaces);
	width += print_hex_prefix(number, base, formaters->flags);
	width += put_n_char('0', formaters->before_zeros);
	if (formaters->precision != 0 || number != 0)
		width += print_hexadecimal_aux(number, base);
	else if (formaters->width != 0)
		width += write(1, " ", 1);
	width += put_n_char(' ', formaters->after_spaces);
	return (width);
}
