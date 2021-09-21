/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:50:36 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/18 18:28:39 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversors(char *string, va_list args, t_formater *formaters)
{
	if (*string == 'c')
		return (print_char(va_arg(args, int), formaters));
	if (*string == 's')
		return (print_string(va_arg(args, char *), formaters));
	if (*string == 'p')
		return (print_pointer(va_arg(args, void *), formaters));
	if (*string == 'd' || *string == 'i')
		return (print_int(va_arg(args, int), formaters));
	if (*string == 'u')
		return (print_unsigned_int(va_arg(args, size_t), formaters));
	if (*string == 'x')
		return (print_hexadecimal(va_arg(args, int), HEX_LOWER, formaters));
	if (*string == 'X')
		return (print_hexadecimal(va_arg(args, int), HEX_UPPER, formaters));
	if (*string == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	print_var(char **string, va_list args, t_formater *formaters)
{
	formaters->flags = 0;
	formaters->width = -1;
	formaters->precision = -1;
	formaters->prefix = 0;
	formaters->chars = 0;
	formaters->before_spaces = 0;
	formaters->after_spaces = 0;
	formaters->before_zeros = 0;
	return (conversors(*string, args, ft_formaters(string, formaters)));
}

int	ft_printf(const char *string, ...)
{
	int			chars;
	va_list		args;
	t_formater	*formaters;

	formaters = malloc(sizeof(t_formater));
	chars = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			chars += print_var((char **)&string, args, formaters);
		}
		else
		{
			write(1, string, 1);
			chars++;
		}
		string++;
	}
	va_end(args);
	free(formaters);
	return (chars);
}
