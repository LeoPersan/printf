/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:34:59 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/04 20:34:59 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_n_char(char c, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}

int	ft_print_char(char c, int *formaters)
{
	int	width;

	width = 1;
	if (!(HAS_MINUS_FLAG(formaters[0])) && formaters[1] > width)
		width += ft_put_n_char(' ', formaters[1] - width);
	write(1, &c, 1);
	if (HAS_MINUS_FLAG(formaters[0]) && formaters[1] > width)
		width += ft_put_n_char(' ', formaters[1] - width);
	return (width);
}

int	ft_print_string(char *string, int *formaters)
{
	int	chars;
	int	width;

	if (!string)
		return write(1, "(null)", 6);
	chars = 0;
	while (string[chars])
		chars++;
	width = 0;
	if (formaters[2] > -1 && chars > formaters[2])
		chars = formaters[2];
	if (!(HAS_MINUS_FLAG(formaters[0])) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	write(1, string, chars);
	if (HAS_MINUS_FLAG(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}

int	ft_print_unsigned_int_aux(size_t number)
{
	char	c;
	int		chars;

	if (number > 9)
	{
		chars = ft_print_unsigned_int_aux(number / 10);
		c = (number % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		chars = 0;
		c = number + '0';
		write(1, &c, 1);
	}
	return (1 + chars);
}

int	ft_print_unsigned_int(unsigned int number, int *formaters)
{
	int				width;
	int				chars;
	unsigned int	number_aux;

	chars = 0;
	number_aux = number;
	while (!chars || number_aux)
	{
		number_aux /= 10;
		chars++;
	}
	width = 0;
	if (!(HAS_MINUS_FLAG(formaters[0])))
	{
		if (formaters[2] > -1 && formaters[2] + chars < formaters[1])
			formaters[1] -= formaters[2] - chars;
		if (!(HAS_ZERO_FLAG(formaters[0])) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		if (HAS_ZERO_FLAG(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char('0', formaters[1] - width - chars);
		while (formaters[2] > -1 &&chars < formaters[2])
		{
			chars++;
			write(1, "0", 1);
		}
	}
	ft_print_unsigned_int_aux(number);
	if (HAS_MINUS_FLAG(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}

int	ft_print_int(long long number, int *formaters)
{
	int			chars;
	int			width;
	int			numbers;
	long long	number_aux;

	chars = (number < 0 || HAS_PLUS_FLAG(formaters[0]));
	numbers = 0;
	number_aux = number;
	while (!numbers || number_aux)
	{
		number_aux /= 10;
		chars++;
		numbers++;
	}
	width = 0;
	if (!(HAS_MINUS_FLAG(formaters[0])))
	{
		if (formaters[2] > -1 && formaters[2] + numbers < formaters[1])
			formaters[1] -= formaters[2] - numbers;
		if (!(HAS_ZERO_FLAG(formaters[0])) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		if (HAS_SPACE_FLAG(formaters[0]) && !formaters[1] && chars == numbers)
		{
			write(1, " ", 1);
			chars++;
			numbers++;
		}
		if (number < 0)
			write(1, "-", 1);
		else if (HAS_PLUS_FLAG(formaters[0]))
			write(1, "+", 1);
		if (HAS_ZERO_FLAG(formaters[0]) && width + chars < formaters[1])
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
	if (HAS_MINUS_FLAG(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}

int	ft_print_hexadecimal_aux(size_t number, char *base)
{
	char	c;
	int		chars;

	if (number > 15)
	{
		chars = ft_print_hexadecimal_aux(number / 16, base);
		c = base[number % 16];
		write(1, &c, 1);
	}
	else
	{
		chars = 0;
		c = base[number];
		write(1, &c, 1);
	}
	return (1 + chars);
}

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
	if (HAS_HASHTAG_FLAG(formaters[0]) && number)
		chars += 2;
	if (!(HAS_MINUS_FLAG(formaters[0])))
	{
		if (formaters[2] > -1 && formaters[2] + numbers < formaters[1])
			formaters[1] -= formaters[2] - numbers;
		if (!(HAS_ZERO_FLAG(formaters[0])) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		if (HAS_HASHTAG_FLAG(formaters[0]) && number)
		{
			if (base[10] == 'A')
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
		if (HAS_ZERO_FLAG(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char('0', formaters[1] - width - chars);
		while (formaters[2] > -1  && numbers < formaters[2])
		{
			chars++;
			numbers++;
			write(1, "0", 1);
		}
	}
	else
	{
		if (HAS_HASHTAG_FLAG(formaters[0]) && number)
		{
			if (base[10] == 'A')
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
	}
	ft_print_hexadecimal_aux(number, base);
	if (HAS_MINUS_FLAG(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}

int	ft_print_pointer(void *pointer, int *formaters)
{
	int	width;
	int	chars;
	size_t	number_aux;

	chars = 0;
	number_aux = (size_t) pointer;
	if (!number_aux)
		return write(1, "(nil)", 5);
	while (number_aux)
	{
		number_aux /= 16;
		chars++;
	}
	width = 2;
	if (!(HAS_MINUS_FLAG(formaters[0])))
	{
		if (!(HAS_ZERO_FLAG(formaters[0])) && width + chars < formaters[1])
			width += ft_put_n_char(' ', formaters[1] - width - chars);
		write(1, "0x", 2);
		if (HAS_ZERO_FLAG(formaters[0]) && width + chars < formaters[1])
			width += ft_put_n_char('0', formaters[1] - width - chars);
	}
	else
		write(1, "0x", 2);
	ft_print_hexadecimal_aux((size_t) pointer, "0123456789abcdef");
	if (HAS_MINUS_FLAG(formaters[0]) && width + chars < formaters[1])
		width += ft_put_n_char(' ', formaters[1] - width - chars);
	return (width + chars);
}

int	ft_conversors(char *string, va_list args, int *formaters)
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
		return (ft_print_hexadecimal(va_arg(args, int), "0123456789abcdef", formaters));
	if (*string == 'X')
		return (ft_print_hexadecimal(va_arg(args, int), "0123456789ABCDEF", formaters));
	if (*string == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_strpos(char *string, char c)
{
	int	pos;

	pos = -1;
	while (string[++pos])
		if (string[pos] == c)
			return (pos);
	return (-1);
}

int	ft_formaters_flags(char **string)
{
	int	flags;
	int	pos;

	flags = 0;
	pos = ft_strpos(FLAGS, **string);
	while (**string && pos > -1)
	{
		if (flags & (1 << pos))
			return (-1);
		flags = flags | (1 << pos);
		(*string)++;
		pos = ft_strpos(FLAGS, **string);
	}
	return (flags);
}

int	ft_formaters_width(char **string)
{
	int	width;

	width = 0;
	while (**string && **string >= '0' && **string <= '9')
		width = (width * 10) + (*(*string)++ - '0');
	return (width);
}

int	ft_formaters_precision(char **string)
{
	int	precision;

	precision = 0;
	if (**string == '.')
		(*string)++;
	else
		return (-1);
	while (**string && **string >= '0' && **string <= '9')
		precision = (precision * 10) + (*(*string)++ - '0');
	return (precision);
}

int	*ft_formaters(char **string, int *formaters)
{
	formaters[0] = ft_formaters_flags(string);
	formaters[1] = ft_formaters_width(string);
	formaters[2] = ft_formaters_precision(string);
	return (formaters);
}

int	ft_print_var(char **string, va_list args)
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
