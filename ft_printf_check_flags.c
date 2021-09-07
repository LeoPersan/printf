/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:45:49 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:45:49 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_has_hashtag_flag(int flags)
{
	return (flags & (1 << 0));
}

int	ft_has_space_flag(int flags)
{
	return (flags & (1 << 1));
}

int	ft_has_plus_flag(int flags)
{
	return (flags & (1 << 2));
}

int	ft_has_minus_flag(int flags)
{
	return (flags & (1 << 3));
}

int	ft_has_zero_flag(int flags)
{
	return (flags & (1 << 4));
}
