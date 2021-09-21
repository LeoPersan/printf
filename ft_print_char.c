/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:41 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/18 18:17:10 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_formater	*calc_formaters(t_formater *formaters)
{
	if (ft_has_minus_flag(formaters->flags))
		formaters->after_spaces = formaters->width - 1;
	else
		formaters->before_spaces = formaters->width - 1;
	return (formaters);
}

int	ft_print_char(char c, t_formater *formaters)
{
	int	width;

	formaters = calc_formaters(formaters);
	width = 0;
	width += ft_put_n_char(' ', formaters->before_spaces);
	width += write(1, &c, 1);
	width += ft_put_n_char(' ', formaters->after_spaces);
	return (width);
}
