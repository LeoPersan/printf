/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:47:19 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/18 17:15:09 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_chars(unsigned int number)
{
	int	chars;

	chars = -1;
	while (!(++chars) || number)
		number /= 10;
	return (chars);
}

static int	print_spaces(int chars, int *formaters)
{
	if (!ft_has_minus_flag(formaters[0])
		&& (!ft_has_zero_flag(formaters[0]) || formaters[2] > -1))
		return (ft_put_n_char(' ', formaters[1] - chars));
	return (0);
}

int	ft_print_unsigned_int(unsigned int number, int *formaters)
{
	int	chars;
	int	numbers;

	chars = count_chars(number);
	numbers = chars;
	if (formaters[2] > chars)
		chars = formaters[2];
	chars += print_spaces(chars, formaters);
	if (ft_has_zero_flag(formaters[0]) && formaters[2] < 0)
		chars += ft_put_n_char('0', formaters[1] - chars);
	ft_put_n_char('0', formaters[2] - numbers);
	if (!number && formaters[2] == 0)
	{
		if (formaters[1] > 0)
			write(1, " ", 1);
		else
			chars--;
	}
	else
		ft_print_unsigned_int_aux(number);
	if (ft_has_minus_flag(formaters[0]))
		chars += ft_put_n_char(' ', formaters[1] - chars);
	return (chars);
}
