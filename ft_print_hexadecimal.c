/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:49 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/18 16:41:47 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_prefix(unsigned int number, char *base, int flags)
{
	if (!ft_has_hashtag_flag(flags) || !number)
		return (0);
	if (base[10] == 'A')
		return (write(1, "0X", 2));
	return (write(1, "0x", 2));
}

static int	before_prefix(int *formaters, int chars, unsigned int number)
{
	if (ft_has_hashtag_flag(formaters[0]) && number)
		chars += 2;
	if (!ft_has_minus_flag(formaters[0])
		&& (!ft_has_zero_flag(formaters[0]) || formaters[2] > -1))
		return (ft_put_n_char(' ', formaters[1] - chars));
	return (0);
}

static int	after_prefix(int *formaters, int chars)
{
	if (!ft_has_minus_flag(formaters[0]) && ft_has_zero_flag(formaters[0]))
		return (ft_put_n_char('0', formaters[1] - chars));
	return (0);
}

static int	count_chars(unsigned int number)
{
	int	chars;

	chars = -1;
	while (!(++chars) || number)
		number /= 16;
	return (chars);
}

int	ft_print_hexadecimal(unsigned int number, char *base, int *formaters)
{
	int	chars;
	int	numbers;

	chars = count_chars(number);
	numbers = chars;
	if (formaters[2] > chars)
		chars = formaters[2];
	chars += before_prefix(formaters, chars, number);
	chars += ft_print_hex_prefix(number, base, formaters[0]);
	chars += after_prefix(formaters, chars);
	ft_put_n_char('0', formaters[2] - numbers);
	if (!number && formaters[2] == 0)
	{
		if (formaters[1] > 0)
			write(1, " ", 1);
		else
			chars--;
	}
	else
		ft_print_hexadecimal_aux(number, base);
	if (ft_has_minus_flag(formaters[0]))
		chars += ft_put_n_char(' ', formaters[1] - chars);
	return (chars);
}
