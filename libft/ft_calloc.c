/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:50:57 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/14 16:00:57 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	int_max;
	size_t	tg_size;
	size_t	i;

	int_max = 2147483647;
	if ((nmemb * size > int_max) || (nmemb > int_max) || (size > int_max))
		tg_size = 0;
	else
		tg_size = size * nmemb;
	p = (char *)malloc(tg_size);
	if (p == NULL)
		return (0);
	i = 0;
	while (i < tg_size)
		p[i++] = 0;
	return ((void *)p);
}
