/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:18:02 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/13 14:33:29 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;
	unsigned int	i;

	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest < src)
	{
		while (i != n)
		{
			p[i] = s[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (i != n)
		{
			p[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
