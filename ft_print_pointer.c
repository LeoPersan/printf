/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:48:47 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/18 16:44:47 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	before_prefix(int *formaters, int chars)
{
	if (!ft_has_minus_flag(formaters[0]) && !ft_has_zero_flag(formaters[0]))
		return (ft_put_n_char(' ', formaters[1] - chars));
	return (0);
}

static int	after_prefix(int *formaters, int chars)
{
	if (!ft_has_minus_flag(formaters[0]) && ft_has_zero_flag(formaters[0]))
		return (ft_put_n_char('0', formaters[1] - chars));
	return (0);
}

static int	count_chars(size_t address)
{
	int	chars;

	if (!address)
		return (3);
	chars = 1;
	while (++chars && address)
		address /= 16;
	return (chars);
}

int	ft_print_pointer(void *pointer, int *formaters)
{
	int		chars;

	chars = count_chars((size_t) pointer);
	chars += before_prefix(formaters, chars);
	write(1, "0x", 2);
	chars += after_prefix(formaters, chars);
	ft_print_hexadecimal_aux((size_t) pointer, HEX_LOWER);
	if (ft_has_minus_flag(formaters[0]))
		chars += ft_put_n_char(' ', formaters[1] - chars);
	return (chars);
}
