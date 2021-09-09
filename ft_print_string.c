/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:49:03 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:49:03 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *string, int *formaters)
{
	int	chars;
	int	width;

	chars = 0;
	if (!string)
		chars = 6;
	else
		while (string && string[chars])
			chars++;
	width = 0;
	if (formaters[2] > -1 && chars > formaters[2])
		chars = formaters[2];
	if (!ft_has_minus_flag(formaters[0]))
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	if (!string)
		write(1, "(null)", chars);
	else
		write(1, string, chars);
	if (ft_has_minus_flag(formaters[0]))
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}
