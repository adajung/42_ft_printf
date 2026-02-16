/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:24:11 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/13 16:52:06 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	temp;
	int	sign;
	int	i;

	temp = 0;
	sign = 1;
	i = 0;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
		temp = temp * 10 + nptr[i++] - '0';
	return (sign * temp);
}
