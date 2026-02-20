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

static int	put_hex(unsigned long long n)
{
	int	ret;

	if (n >= 16)
	{
		ret = put_hex(n / 16);
		if (ret < 0)
			return (-1);
	}
	else
		ret = 0;
	if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
		return (-1);
	return (ret + 1);
}

int	print_type_p(format *tempFormat, va_list ap)
{
	unsigned long long	value;
	int					len;

	(void)tempFormat;
	value = (unsigned long long)(uintptr_t)va_arg(ap, void *);
	if (value == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = put_hex(value);
	if (len < 0)
		return (-1);
	return (len + 2);
}
