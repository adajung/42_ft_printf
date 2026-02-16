/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:56:31 by hwalee            #+#    #+#             */
/*   Updated: 2026/01/30 13:56:32 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_type_d(format *tempFormat, va_list ap)
{
    char c;

    c = (char)va_arg(ap, int);

    if (tempFormat->minus)
    {
        write(1, &c, 1);
        tempFormat->width--;
    }
    while (tempFormat->width--)
        write(1, " ", 1);
}