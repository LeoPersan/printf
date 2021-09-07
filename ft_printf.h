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

# define FLAGS  "# +-0"
# define HEX_LOWER  "0123456789abcdef"
# define HEX_UPPER  "0123456789ABCDEF"

int	ft_has_hashtag_flag(int flags);
int	ft_has_space_flag(int flags);
int	ft_has_plus_flag(int flags);
int	ft_has_minus_flag(int flags);
int	ft_has_zero_flag(int flags);

int	ft_put_n_char(char c, size_t n);
int	ft_print_unsigned_int_aux(size_t number);
int	ft_print_hexadecimal_aux(size_t number, char *base);

int	ft_print_char(char c, int *formaters);
int	ft_print_string(char *string, int *formaters);
int	ft_print_int(long long number, int *formaters);
int	ft_print_pointer(void *pointer, int *formaters);
int	ft_print_unsigned_int(unsigned int number, int *formaters);
int	ft_print_hexadecimal(unsigned int number, char *base, int *formaters);

int	*ft_formaters(char **string, int *formaters);

int	ft_printf(const char *string, ...);

#endif
