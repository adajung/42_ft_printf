/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:35:20 by hwalee            #+#    #+#             */
/*   Updated: 2026/02/20 12:40:00 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex(unsigned int n, const char *base)
{
	if (n >= 16)
		put_hex(n / 16, base);
	write(1, &base[n % 16], 1);
}

void	print_type_x(format *tempFormat, va_list ap)
{
	unsigned int	value;

	(void)tempFormat;
	value = va_arg(ap, unsigned int);
	put_hex(value, "0123456789abcdef");
}
