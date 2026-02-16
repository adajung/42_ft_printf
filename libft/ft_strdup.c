/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:34:51 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 18:15:10 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*p;

	size = ft_strlen(s) + 1;
	p = (char *)malloc(size * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
