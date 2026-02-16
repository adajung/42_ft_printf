/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:49:15 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 18:59:54 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*p;

	size = 0;
	i = 0;
	if (ft_strlen(s) > start)
	{
		while ((s[start + size]) && (size < len))
			size++;
	}
	p = (char *)malloc((size + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	while (i < size)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
