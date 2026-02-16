/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:23:01 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 15:52:31 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	unsigned_c;

	i = 0;
	unsigned_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == unsigned_c)
			return ((char *)(s + i));
		i++;
	}
	if (unsigned_c == '\0')
		return ((char *)(s + i));
	return (0);
}
