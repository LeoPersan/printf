/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_formaters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:45:49 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/18 17:33:41 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strpos(char *string, char c)
{
	int	pos;

	pos = -1;
	while (string[++pos])
		if (string[pos] == c)
			return (pos);
	return (-1);
}

static int	ft_formaters_flags(char **string)
{
	int	flags;
	int	pos;

	flags = 0;
	pos = ft_strpos(FLAGS, **string);
	while (**string && pos > -1)
	{
		flags = flags | (1 << pos);
		(*string)++;
		pos = ft_strpos(FLAGS, **string);
	}
	return (flags);
}

static int	ft_formaters_width(char **string)
{
	int	width;

	width = 0;
	while (**string && **string >= '0' && **string <= '9')
		width = (width * 10) + (*(*string)++ - '0');
	return (width);
}

static int	ft_formaters_precision(char **string)
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

t_formater	*ft_formaters(char **string, t_formater *formaters)
{
	formaters->flags = ft_formaters_flags(string);
	formaters->width = ft_formaters_width(string);
	formaters->precision = ft_formaters_precision(string);
	return (formaters);
}
