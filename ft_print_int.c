/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:47:43 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:47:43 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(long long number, int *formaters)
{
	int			chars;
	int			width;
	int			numbers;
	long long	number_aux;

	chars = (number < 0 || ft_has_plus_flag(formaters[0]));
	numbers = 0;
	number_aux = number;
	while (!numbers || number_aux)
	{
		number_aux /= 10;
		chars++;
		numbers++;
	}
	width = 0;
	if (!(ft_has_minus_flag(formaters[0])))
	{
		if (formaters[2] > -1 && formaters[2] + numbers < formaters[1])
			formaters[1] -= formaters[2] - numbers;
		if (!ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		if (ft_has_space_flag(formaters[0])
			&& !formaters[1] && chars == numbers)
		{
			write(1, " ", 1);
			chars++;
			numbers++;
		}
		if (number < 0)
			write(1, "-", 1);
		else if (ft_has_plus_flag(formaters[0]))
			write(1, "+", 1);
		if (ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char('0', formaters[1] - width - chars);
		while (formaters[2] > -1 && numbers < formaters[2])
		{
			write(1, "0", 1);
			chars++;
			numbers++;
		}
	}
	else
		if (number < 0)
			write(1, "-", 1);
	if (number < 0)
		number *= -1;
	ft_print_unsigned_int_aux(number);
	if (ft_has_minus_flag(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}
