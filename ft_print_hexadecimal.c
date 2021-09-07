/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:49 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:46:49 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(unsigned int number, char *base, int *formaters)
{
	int				width;
	int				chars;
	int				numbers;
	unsigned int	number_aux;

	chars = 0;
	numbers = 0;
	number_aux = number;
	while (!numbers || number_aux)
	{
		number_aux /= 16;
		chars++;
		numbers++;
	}
	width = 0;
	if (ft_has_hashtag_flag(formaters[0]) && number)
		chars += 2;
	if (!ft_has_minus_flag(formaters[0]))
	{
		if (formaters[2] > -1 && formaters[2] + numbers < formaters[1])
			formaters[1] -= formaters[2] - numbers;
		if (!ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		if (ft_has_hashtag_flag(formaters[0]) && number)
		{
			if (base[10] == 'A')
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
		if (ft_has_zero_flag(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char('0', formaters[1] - width - chars);
		while (formaters[2] > -1 && numbers < formaters[2])
		{
			chars++;
			numbers++;
			write(1, "0", 1);
		}
	}
	else
	{
		if (ft_has_hashtag_flag(formaters[0]) && number)
		{
			if (base[10] == 'A')
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
	}
	ft_print_hexadecimal_aux(number, base);
	if (ft_has_minus_flag(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}
