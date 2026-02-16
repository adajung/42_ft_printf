/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:46:51 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/13 16:53:40 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	byte;
	unsigned char	*p;
	size_t			i;

	byte = (unsigned char)c;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = byte;
	return (s);
}
