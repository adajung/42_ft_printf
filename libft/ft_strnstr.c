/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:38:14 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/13 16:59:20 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_size;

	i = 0;
	l_size = ft_strlen(little);
	if (len < l_size || ft_strlen(big) < l_size)
		return (0);
	if (len == 0 || l_size == 0)
		return ((char *)big);
	while (i + l_size - 1 < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && (little[j]))
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
