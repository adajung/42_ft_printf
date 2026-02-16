/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:30:58 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 19:28:10 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	i;
	unsigned char	*unsigned_dst;
	unsigned char	*unsigned_src;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	unsigned_dst = (unsigned char *)dest;
	unsigned_src = (unsigned char *)src;
	while (i < n)
	{
		unsigned_dst[i] = unsigned_src[i];
		i++;
	}
	return (dest);
}
