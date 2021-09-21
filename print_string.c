/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:49:03 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/18 18:35:59 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_formater	*calc_formaters(char *string, t_formater *formaters)
{
	if (!string)
		formaters->chars = 6;
	else
		while (string[formaters->chars])
			formaters->chars++;
	if (formaters->precision > -1 && formaters->chars > formaters->precision)
		formaters->chars = formaters->precision;
	if (has_minus_flag(formaters->flags))
		formaters->after_spaces = formaters->width - formaters->chars;
	else
		formaters->before_spaces = formaters->width - formaters->chars;
	return (formaters);
}

int	print_string(char *string, t_formater *formaters)
{
	int	width;

	width = 0;
	formaters = calc_formaters(string, formaters);
	width += put_n_char(' ', formaters->before_spaces);
	if (!string)
		width += write(1, "(null)", formaters->chars);
	else
		width += write(1, string, formaters->chars);
	width += put_n_char(' ', formaters->after_spaces);
	return (width);
}
