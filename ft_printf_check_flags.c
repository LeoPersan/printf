/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:45:49 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/07 17:45:49 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_hashtag_flag(int flags)
{
	return (flags & (1 << 0));
}

int	has_space_flag(int flags)
{
	return (flags & (1 << 1));
}

int	has_plus_flag(int flags)
{
	return (flags & (1 << 2));
}

int	has_minus_flag(int flags)
{
	return (flags & (1 << 3));
}

int	has_zero_flag(int flags)
{
	return (flags & (1 << 4));
}
