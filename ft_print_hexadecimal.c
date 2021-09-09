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

static void	ft_print_hex_prefix(unsigned int number, char *base, int flags)
{
	if (!ft_has_hashtag_flag(flags) || !number)
		return ;
	if (base[10] == 'A')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
}

int	ft_print_hexadecimal(unsigned int number, char *base, int *formaters)
{
	int				chars;
	int				numbers;
	unsigned int	number_aux;

	chars = -1;
	number_aux = number;
	while (!(++chars) || number_aux)
		number_aux /= 16;
	numbers = chars;
	if (formaters[2] > chars)
		chars = formaters[2];
	if (ft_has_hashtag_flag(formaters[0]) && number)
		chars += 2;
	if (!ft_has_minus_flag(formaters[0]))
	{
		if (!ft_has_zero_flag(formaters[0]) || formaters[2] > -1)
			chars += ft_put_n_char(' ', formaters[1] - chars);
		ft_print_hex_prefix(number, base, formaters[0]);
		if (ft_has_zero_flag(formaters[0]) || formaters[2] < 0)
			chars += ft_put_n_char('0', formaters[1] - chars);
	}
	else
		ft_print_hex_prefix(number, base, formaters[0]);
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
