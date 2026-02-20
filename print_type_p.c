/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:56:47 by hwalee            #+#    #+#             */
/*   Updated: 2026/02/20 12:40:00 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static void	put_hex(unsigned long long n)
{
	if (n >= 16)
		put_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	print_type_p(format *tempFormat, va_list ap)
{
	unsigned long long	value;

	(void)tempFormat;
	value = (unsigned long long)(uintptr_t)va_arg(ap, void *);
	if (value == 0)
		return ((void)write(1, "(nil)", 5));
	write(1, "0x", 2);
	put_hex(value);
}
