/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:54:19 by hwalee            #+#    #+#             */
/*   Updated: 2026/01/28 11:54:27 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
#include <stdarg.h>

typedef struct format {
    int hash;
    int space;
    int plus;
    int minus;
    int zero;
    int dot;
    int width;
    int precision;
    char type;
} format;

void print_type_c(format *tempFormat, va_list ap);
void print_type_s(format *tempFormat, va_list ap);
void print_type_p(format *tempFormat, va_list ap);
void print_type_d(format *tempFormat, va_list ap);
void print_type_i(format *tempFormat, va_list ap);
void print_type_u(format *tempFormat, va_list ap);
void print_type_x(format *tempFormat, va_list ap);
void print_type_X(format *tempFormat, va_list ap);
int ft_printf(const char *, ...);

#endif