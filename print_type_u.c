/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:35:14 by hwalee            #+#    #+#             */
/*   Updated: 2026/01/30 13:57:02 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_type_u(format *tempFormat, va_list ap)
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