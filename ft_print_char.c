/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:41 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:46:41 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, int *formaters)
{
	int	width;

	width = 1;
	if (!ft_has_minus_flag(formaters[0]))
		width += ft_put_n_char(' ', formaters[1] - width);
	write(1, &c, 1);
	if (ft_has_minus_flag(formaters[0]))
		width += ft_put_n_char(' ', formaters[1] - width);
	return (width);
}
