/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:33:54 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/04 20:33:54 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define FLAGS					"# +-0"
# define HAS_HASHTAG_FLAG(f)	f&(1<<0)
# define HAS_SPACE_FLAG(f)		f&(1<<1)
# define HAS_PLUS_FLAG(f)		f&(1<<2)
# define HAS_MINUS_FLAG(f)		f&(1<<3)
# define HAS_ZERO_FLAG(f)		f&(1<<4)

int	ft_printf(const char *string, ...);

#endif
