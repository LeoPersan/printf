/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:50:36 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:50:36 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversors(char *string, va_list args, int *formaters)
{
	if (*string == 'c')
		return (ft_print_char(va_arg(args, int), formaters));
	if (*string == 's')
		return (ft_print_string(va_arg(args, char *), formaters));
	if (*string == 'p')
		return (ft_print_pointer(va_arg(args, void *), formaters));
	if (*string == 'd' || *string == 'i')
		return (ft_print_int(va_arg(args, int), formaters));
	if (*string == 'u')
		return (ft_print_unsigned_int(va_arg(args, size_t), formaters));
	if (*string == 'x')
		return (ft_print_hexadecimal(va_arg(args, int), HEX_LOWER, formaters));
	if (*string == 'X')
		return (ft_print_hexadecimal(va_arg(args, int), HEX_UPPER, formaters));
	if (*string == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	ft_print_var(char **string, va_list args)
{
	int	formaters[3];

	return (ft_conversors(*string, args, ft_formaters(string, formaters)));
}

int	ft_printf(const char *string, ...)
{
	int		chars;
	va_list	args;

	chars = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			chars += ft_print_var((char **)&string, args);
		}
		else
		{
			write(1, string, 1);
			chars++;
		}
		string++;
	}
	va_end(args);
	return (chars);
}
