/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:11:21 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/14 16:03:35 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_and_rcp(char *src)
{
	char	*p;
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	p = (char *)malloc(len * sizeof(char) + 1);
	if (p == NULL)
		return (0);
	i = 0;
	while (len != 0)
		p[i++] = src[--len];
	p[i] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char	temp[12];
	int		i;
	int		sign;

	if (n == -2147483648)
		return (alloc_and_rcp("8463847412-"));
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	i = 0;
	if (n == 0)
		temp[i++] = '0';
	while (n != 0)
	{
		temp[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		temp[i++] = '-';
	temp[i] = '\0';
	return (alloc_and_rcp(temp));
}
