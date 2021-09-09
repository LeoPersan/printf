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
	int				chars;
	int				numbers;
	unsigned int	number_aux;

	chars = -1;
	number_aux = number;
	while (!(++chars) || number_aux)
		number_aux /= 10;
	numbers = chars;
	if (formaters[2] > chars)
		chars = formaters[2];
	if (!ft_has_minus_flag(formaters[0]))
	{
		if (!ft_has_zero_flag(formaters[0]) || formaters[2] > -1)
			chars += ft_put_n_char(' ', formaters[1] - chars);
	}
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
