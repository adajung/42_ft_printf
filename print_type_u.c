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

static int	put_unsigned(unsigned int n)
{
	char	c;
	int		ret;

	if (n >= 10)
	{
		ret = put_unsigned(n / 10);
		if (ret < 0)
			return (-1);
	}
	else
		ret = 0;
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (ret + 1);
}

int	print_type_u(format *tempFormat, va_list ap)
{
	unsigned int	value;

	(void)tempFormat;
	value = va_arg(ap, unsigned int);
	return (put_unsigned(value));
}
