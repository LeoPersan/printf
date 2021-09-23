/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoperei <leopso1990@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:33:54 by leoperei          #+#    #+#             */
/*   Updated: 2021/09/22 20:52:11 by leoperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define FLAGS		"# +-0"
# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

typedef unsigned int	t_uint;
typedef struct s_formater
{
	int	flags;
	int	width;
	int	precision;
	int	prefix;
	int	chars;
	int	before_spaces;
	int	after_spaces;
	int	before_zeros;
}	t_formater;

int			has_hashtag_flag(int flags);
int			has_space_flag(int flags);
int			has_plus_flag(int flags);
int			has_minus_flag(int flags);
int			has_zero_flag(int flags);

int			put_n_char(char c, int n);
int			print_unsigned_int_aux(size_t number);
int			print_hexadecimal_aux(size_t number, char *base);

int			print_char(char c, t_formater *formaters);
int			print_string(char *string, t_formater *formaters);
int			print_int(long long number, t_formater *formaters);
int			print_pointer(void *pointer, t_formater *formaters);
int			print_unsigned_int(t_uint number, t_formater *formaters);
int			print_hexadecimal(t_uint number, char *base, t_formater *formaters);

t_formater	*ft_formaters(char **string, t_formater *formaters);

int			ft_printf(const char *string, ...);

#endif
