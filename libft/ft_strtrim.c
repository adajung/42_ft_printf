/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:31:30 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 18:29:56 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*p;

	i = 0;
	j = ft_strlen(s1);
	while (isinset(s1[i], set) == 1)
		i++;
	while ((i < j) && (isinset(s1[j - 1], set) == 1))
		j--;
	p = (char *)malloc((j - i + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	k = 0;
	while (i + k < j)
	{
		p[k] = s1[i + k];
		k++;
	}
	p[k] = '\0';
	return (p);
}
