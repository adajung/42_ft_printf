/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:34:50 by hwalee            #+#    #+#             */
/*   Updated: 2026/02/20 12:40:00 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type_s(format *tempFormat, va_list ap)
{
	char	*str;
	int		len;

	(void)tempFormat;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}
