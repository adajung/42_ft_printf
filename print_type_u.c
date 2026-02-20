/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:35:14 by hwalee            #+#    #+#             */
/*   Updated: 2026/02/20 12:40:00 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_unsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
		put_unsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	print_type_u(format *tempFormat, va_list ap)
{
	unsigned int	value;

	(void)tempFormat;
	value = va_arg(ap, unsigned int);
	put_unsigned(value);
}
